# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.1.2
CATEGORIES=	mail
MASTER_SITES=	http://www.list.org/ \
		${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mailman
EXTRACT_SUFX=	.tgz

MAINTAINER=	khera@kcilink.com
COMMENT=	A mailing list manager (MLM) with a user-friendly web front-end

RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx
.if defined(WITH_CHINESE)
RUN_DEPENDS+=	${PYTHONPREFIX_SITELIBDIR}/cjkcodecs.pth:${PORTSDIR}/converters/py-cjkcodecs
.endif

HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--prefix=${MAILMANDIR} --with-python=${PYTHON_CMD} \
		--with-username=${MM_USERNAME} \
		--with-groupname=${MM_GROUPNAME} \
		--with-mail-gid=${MAIL_GID} --with-cgi-gid=${CGI_GID}

.include <bsd.port.pre.mk>

# The Mailman port supports a number of variables that may be tweaked at
# build time.  Getting the values of some of them right is crucial!
# Perform a "make options" to see more information on these variables.
#
MM_USERNAME?=	mailman
MM_USERID?=	91
MM_GROUPNAME?=	${MM_USERNAME}
MM_GROUPID?=	${MM_USERID}
MM_DIR?=	mailman
.if ${OSVERSION} >= 450000
MAIL_GID?=	mailnull
.else
MAIL_GID?=	daemon
.endif
CGI_GID?=	www
IMGDIR=		www/icons
#
# End of user-configurable variables.

MAILMANDIR=	${PREFIX}/${MM_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGOPTS=	${FILESDIR}/pkg-opts
PLIST_SUB+=	MMDIR=${MM_DIR} IMGDIR=${IMGDIR}
DOCFILES=	ACKNOWLEDGMENTS BUGS FAQ INSTALL NEWS README README-I18N.en \
	  	README.CONTRIB README.EXIM README.NETSCAPE README.POSTFIX \
		README.QMAIL README.SENDMAIL README.USERAGENT TODO UPGRADING
IMGFILES=	PythonPowered.png mailman.jpg mm-icon.png

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

post-extract:
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} '                        = IMPORTANT NOTICE =                             '; \
	   ${ECHO_MSG} 'Getting the values of certain build time variables right is CRUCIAL if   '; \
	   ${ECHO_MSG} 'you want your Mailman installation to function!  Pay specific attention  '; \
	   ${ECHO_MSG} 'to the value of MAIL_GID if you use an alternative MTA (not Sendmail).   '; \
	   ${ECHO_MSG} '                                                                         '; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@ ${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  ${WRKSRC}/Mailman/Defaults.py.in

pre-configure:
# Mailman's configure script needs the "mailman" user/group to exist, so
# $PKGINSTALL has to be patched before the do-configure target executes.
	@ ${SED} \
	  -e 's#%%USER%%#${MM_USERNAME}#g' -e 's#%%UID%%#${MM_USERID}#g' \
	  -e 's#%%GROUP%%#${MM_GROUPNAME}#g' -e 's#%%GID%%#${MM_GROUPID}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' pkg-install > \
	  ${PKGINSTALL}
	@ ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-configure:
	@ ${SED} \
	  -e 's#%%USER%%#${MM_USERNAME}#g' -e 's#%%GROUP%%#${MM_GROUPNAME}#g' \
	  -e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' \
	  pkg-deinstall > ${PKGDEINSTALL}
	@ ${SED} -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' \
	  -e 's#%%DOCSDIR%%#${DOCSDIR}#g' -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  pkg-message > ${PKGMESSAGE}

pre-install:
	@ ${SH} ${PKGREQ} INSTALL
	@ ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for dir in cron scripts
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MAILMANDIR}/${dir}
.endfor
	@ ${CHGRP} -R ${MM_GROUPNAME} ${MAILMANDIR}
	@ ${MKDIR} ${PREFIX}/${IMGDIR}
.for imgfile in ${IMGFILES}
	@ ${CP} ${MAILMANDIR}/icons/${imgfile} ${PREFIX}/${IMGDIR}
.endfor
	@ uudecode -p ${FILESDIR}/powerlogo.gif.uue > \
	  ${PREFIX}/${IMGDIR}/powerlogo.gif
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${FILESDIR}/FreeBSD-post-install-notes ${DOCSDIR}
.for docfile in ${DOCFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@ ${INSTALL_SCRIPT} ${WRKSRC}/misc/mailman \
	  ${PREFIX}/etc/rc.d/mailman.sh
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
