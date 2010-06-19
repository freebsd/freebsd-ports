# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
DISTVERSION=	2.1.12
CATEGORIES?=	mail
MASTER_SITES=	SF/${PORTNAME}/Mailman%202.1%20%28stable%29/${PORTVERSION} \
		http://www.list.org/

EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	mailman

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A mailing list manager (MLM) with a user-friendly web front-end

OPTIONS=	SENDMAIL "for use with sendmail" off \
		EXIM3 "for use with exim3" off \
		EXIM4 "for use with exim4" off \
		POSTFIX "for use with postfix" off \
		COURIER "for use with courier" off \
		CHINESE "support for Chinese mailing lists" off \
		HTDIG "htdig integration patches" off

HAS_CONFIGURE=	yes
USE_PYTHON=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS+=	--prefix=${MAILMANDIR} --with-python=${PYTHON_CMD} \
		--with-username=${MM_USERNAME} \
		--with-groupname=${MM_GROUPNAME} \
		--with-mail-gid=${MAIL_GID} --with-cgi-gid=${CGI_GID}
SUB_FILES=	pkg-message
SUB_LIST+=	MAILMANDIR=${MAILMANDIR}
USE_RC_SUBR=	mailman

# The Mailman port supports a number of variables that may be tweaked at
# build time.  Getting the values of some of them right is crucial!
#
MM_USERNAME?=	mailman
MM_USERID?=	91
MM_GROUPNAME?=	${MM_USERNAME}
MM_GROUPID?=	${MM_USERID}
MM_DIR?=	mailman
CGI_GID?=	www
IMGDIR?=	www/icons
#
# End of user-configurable variables.

MAILMANDIR=	${PREFIX}/${MM_DIR}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PLIST_SUB+=	MMDIR=${MM_DIR} IMGDIR=${IMGDIR}
DOCFILES=	ACKNOWLEDGMENTS BUGS FAQ INSTALL NEWS README README-I18N.en \
	  	README.CONTRIB README.NETSCAPE \
		README.USERAGENT TODO UPGRADING \
		doc/mailman-admin.txt \
		doc/mailman-install.txt \
		doc/mailman-member.txt

IMGFILES=	PythonPowered.png mailman.jpg mm-icon.png

.include <bsd.port.pre.mk>

.if defined(WITH_SENDMAIL)
.if defined(WITH_EXIM3) || defined(WITH_EXIM4) || defined(WITH_POSTFIX) || \
defined(WITH_COURIER)
BROKEN=	choose only one MTA integration
.endif
MAIL_GID?=	mailnull
.endif

.if defined(WITH_EXIM3)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM4) || defined(WITH_POSTFIX) || \
defined(WITH_COURIER)
BROKEN=	choose only one MTA integration
.endif
MAIL_GID?=	nobody
.endif

.if defined(WITH_EXIM4)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM3) || defined(WITH_POSTFIX) || \
defined(WITH_COURIER)
BROKEN=	choose only one MTA integration
.endif
MAIL_GID?=	mail
.endif

.if defined(WITH_POSTFIX)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM3) || defined(WITH_EXIM4) || \
defined(WITH_COURIER)
BROKEN=	choose only one MTA integration
.endif
MAIL_GID?=	mailman
EXTRA_PATCHES+=	${FILESDIR}/postfix-verp.diff
.endif

.if defined(WITH_COURIER)
.if defined(WITH_SENDMAIL) || defined(WITH_EXIM3) || defined(WITH_EXIM4) || \
defined(WITH_POSTFIX)
BROKEN=	choose only one MTA integration
.endif
MAIL_GID?=	courier
.endif

.if defined(WITH_CHINESE)
RUN_DEPENDS+=	${PYTHONPREFIX_SITELIBDIR}/cjkcodecs.pth:${PORTSDIR}/converters/py-cjkcodecs
.endif

.if defined(WITH_HTDIG)
PATCH_SITES+=	http://www.openinfo.co.uk/mm/patches/444879/:patch1 \
		http://www.openinfo.co.uk/mm/patches/444884/:patch2
PATCHFILES+=	indexing-${DISTVERSION}-0.1.patch.gz:patch1 \
		htdig-${DISTVERSION}-0.1.patch.gz:patch2
PATCH_DIST_STRIP=	-p1
PKGNAMESUFFIX+=	-with-htdig
RUN_DEPENDS+=	htdig:${PORTSDIR}/textproc/htdig
PLIST_SUB+=	SUB_HTDIG=""
.else
PLIST_SUB+=	SUB_HTDIG="@comment "
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may change the following build options:"
	@${ECHO} "MM_USERNAME=mailman	The username of the Mailman user."
	@${ECHO} "MM_USERID=91		The user ID of the Mailman user."
	@${ECHO} "MM_GROUPNAME=mailman	The group to which the Mailman user will belong."
	@${ECHO} "MM_GROUPID=MM_USERID	The group ID for the Mailman user."
	@${ECHO} "MM_DIR=mailman		Mailman will be installed in ${PREFIX}/${MM_DIR}."
	@${ECHO} "CGI_GID=www		The group name or id under which your web server executes CGI scripts."
	@${ECHO} "IMGDIR=www/icons	Icon images will be installed in ${PREFIX}/${IMGDIR}."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  ${WRKSRC}/Mailman/Defaults.py.in

pre-configure::
# Mailman's configure script needs the "mailman" user/group to exist, so
# $PKGINSTALL has to be patched before the do-configure target executes.
	@${SED} \
	  -e 's#%%USER%%#${MM_USERNAME}#g' -e 's#%%UID%%#${MM_USERID}#g' \
	  -e 's#%%GROUP%%#${MM_GROUPNAME}#g' -e 's#%%GID%%#${MM_GROUPID}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' ${MASTERDIR}/pkg-install > \
	  ${PKGINSTALL}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-configure:
	@${SED} \
	  -e 's#%%USER%%#${MM_USERNAME}#g' -e 's#%%GROUP%%#${MM_GROUPNAME}#g' \
	  -e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' \
	  ${MASTERDIR}/pkg-deinstall > ${PKGDEINSTALL}
# port system auditors complain if dir is created prior to install
# but configure demands it be there.  we delete it now if empty,
# so it will be re-created.  For existing installs, this is ignored
	@- ${RMDIR} ${MAILMANDIR} 2> /dev/null

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${RM} -f ${MAILMANDIR}/pythonlib/*.egg-info
.for dir in cron scripts
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MAILMANDIR}/${dir}
.endfor
	@${CHGRP} -R ${MM_GROUPNAME} ${MAILMANDIR}
	@${MKDIR} ${PREFIX}/${IMGDIR}
.for imgfile in ${IMGFILES}
	@${CP} ${MAILMANDIR}/icons/${imgfile} ${PREFIX}/${IMGDIR}
.endfor
	@uudecode -p ${FILESDIR}/powerlogo.gif.uue > \
	  ${PREFIX}/${IMGDIR}/powerlogo.gif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/FreeBSD-post-install-notes ${DOCSDIR}
.for docfile in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_POSTFIX)
	@if [ "x`${LOCALBASE}/sbin/postconf -h myhostname`" != "xlocalhost" ]; then \
		${ECHO_CMD} ""; \
		${ECHO_CMD} "Your Postfix hostname is non-default."; \
		${ECHO_CMD} -n "You must add \"\$$SMTPHOST = "; \
		${ECHO_CMD} -n `${LOCALBASE}/sbin/postconf -h myhostname`; \
		${ECHO_CMD} "\" to the bottom of mm_cfg.py."; \
		${ECHO_CMD} ""; \
		fi
.endif

.include <bsd.port.post.mk>
