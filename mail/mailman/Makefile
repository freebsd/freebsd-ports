# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.0.8
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.list.org/ \
		${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mailman
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${MAILMANDIR} \
		--with-python=${PYTHON_CMD} \
		--with-mail-gid=${MAIL_GID} --with-cgi-gid=${CGI_GID}
USE_PYTHON=	yes
PKGOPTS=	${FILESDIR}/pkg-opts

.include <bsd.port.pre.mk>

# The Mailman port supports a number of variables that may be tweaked at
# build time.  Getting the values of some of them right is crucial!
# Perform a "make options" to see more information on these variables.
#
USERNAME?=	mailman
USERID?=	91
GROUPNAME?=	${USERNAME}
GROUPID?=	${USERID}
MMDIR?=		mailman
.if ${OSVERSION} >= 450000
MAIL_GID?=	26
.else
MAIL_GID?=	1
.endif
CGI_GID?=	80

MAILMANDIR=	${PREFIX}/${MMDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PLIST_SUB=	MMDIR=${MMDIR} MMGRP=${GROUPNAME}

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${PERL} -ne '/^#/ || /^\s/ && print || \
	  print sprintf "* %s [%s]\n  %s", split(/\|/)' ${PKGOPTS}

post-extract:
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

pre-configure:
	@ ${SED} -e 's#%%USER%%#${USERNAME}#g' -e 's#%%UID%%#${USERID}#g' \
	  -e 's#%%GROUP%%#${GROUPNAME}#g' -e 's#%%GID%%#${GROUPID}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' pkg-install > \
	  ${PKGINSTALL}
# Mailman's configure script needs the "mailman" user/group to exist.
	@ ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-configure:
	@ ${SED} -e 's#%%USER%%#${USERNAME}#g' \
	  -e 's#%%GROUP%%#${GROUPNAME}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' pkg-deinstall > \
	  ${PKGDEINSTALL}
	@ ${SED} -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' \
	  -e 's#%%DOCSDIR%%#${DOCSDIR}#g' pkg-message > ${PKGMESSAGE}

pre-install:
	@ ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for dir in cron scripts
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MAILMANDIR}/${dir}
.endfor
	@ ${CHGRP} -R ${GROUPNAME} ${MAILMANDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in BUGS FAQ INSTALL NEWS README* UPGRADING
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
