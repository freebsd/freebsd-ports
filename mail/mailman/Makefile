# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.0.8
PORTREVISION=	3
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

.include <bsd.port.pre.mk>

# These variables may be tweaked if required.  However, it is recommended
# that the USERID and GROUPID not be changed.
#
USERNAME?=	mailman
USERID?=	91
GROUPNAME?=	${USERNAME}
GROUPID?=	${USERID}
MMDIR?=		mailman

# Getting the value of MAIL_GID right is crucial to getting Mailman to work
# with your MTA.  By default, this port works with sendmail.  If you're using
# an alternative MTA installed from ports, you should set MAIL_GID at build
# time according to the following table.  (Please contact this port's
# maintainer if you can fill in the blanks, or to report mistakes!)
#
# MTA     | MAIL_GID | Submitted by
# Exim    | 6        | <wjv>
# Postfix | 65534    | <shamrock@cypherpunks.to>
# Qmail   | ???      |
#
.if ${OSVERSION} >= 450000
MAIL_GID?=	26
.else
MAIL_GID?=	1
.endif

# By default, this port works with the current port of Apache.  If your WWW
# server executes CGI scripts under a different GID, you'll have to set this
# at build time.
CGI_GID?=	80

MAILMANDIR=	${PREFIX}/${MMDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PLIST_SUB=	MMDIR=${MMDIR} MMGRP=${GROUPNAME}

pre-configure:
	@ ${SED} -e 's#%%USER%%#${USERNAME}#g' -e 's#%%UID%%#${USERID}#g' \
	  -e 's#%%GROUP%%#${GROUPNAME}#g' -e 's#%%GID%%#${GROUPID}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' pkg-install > \
	  ${PKGINSTALL}
	@ ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-configure:
	@ ${SED} -e 's#%%USER%%#${USERNAME}#g' \
	  -e 's#%%GROUP%%#${GROUPNAME}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' pkg-deinstall > \
	  ${PKGDEINSTALL}
	@ ${SED} -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' \
	  -e 's#%%DOCSDIR%%#${DOCSDIR}#g' pkg-message > ${PKGMESSAGE}

pre-build:
.if !defined(BATCH)
	@ ${ECHO_MSG} "-------------------------------------------------------"
	@ ${ECHO_MSG} "  If you're using an alternative MTA (not Sendmail)"
	@ ${ECHO_MSG} "  OR an older version of Sendmail, you may have to"
	@ ${ECHO_MSG} "  set MAIL_GID to the gid under which your MTA is"
	@ ${ECHO_MSG} "  executing.  See the comments in the port's"
	@ ${ECHO_MSG} "  Makefile for further information."
	@ ${ECHO_MSG} "-------------------------------------------------------"
.endif

post-install:
.for dir in cron scripts
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MAILMANDIR}/${dir}
.endfor
	@ ${CHGRP} -R ${GROUPNAME} ${MAILMANDIR}
	@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in BUGS FAQ INSTALL NEWS README* UPGRADING
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
