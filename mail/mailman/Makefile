# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.0.8
PORTREVISION=	1
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

# These variables may be tweaked if required.  However, it is recommended
# that the USERID and GROUPID not be changed.
#
USERNAME?=	mailman
USERID?=	91
GROUPNAME?=	${USERNAME}
GROUPID?=	${USERID}
MMDIR?=		mailman

# The default value of '1' for MAIL_GID works with sendmail.  If you're using
# an alternative MTA installed from ports, you should set MAIL_GID at build
# time according to the following table.  (Please contact this port's
# maintainer if you can fill in the blanks!)
#
# MTA     | MAIL_GID
# Exim    | 6
# Postfix | ???
# Qmail   | ???
#
MAIL_GID?=	1
CGI_GID?=	80

MAILMANDIR=	${PREFIX}/${MMDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST_SUB=	MMDIR=${MMDIR}

pre-configure:
# Add the username, uid, group and gid
# ${SH} ${FILESDIR}/configure.sh ${USERNAME} ${USERID} ${MAILMANDIR}

	@ ${SED} -e 's#%%USER%%#${USERNAME}#g' -e 's#%%UID%%#${USERID}#g' \
	  -e 's#%%GROUP%%#${GROUPNAME}#g' -e 's#%%GID%%#${GROUPID}#g' \
	  -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' pkg-install > \
	  ${PKGINSTALL}
	@ ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

# Create the dir and the correct permissions for it.
#${MKDIR} ${MAILMANDIR}
#${CHOWN} ${USERNAME}:${USERNAME} ${MAILMANDIR}
#${CHMOD} 2775 ${MAILMANDIR}

post-configure:
	@ ${SED} -e 's#%%MAILMANDIR%%#${MAILMANDIR}#g' \
	  -e 's#%%DOCSDIR%%#${DOCSDIR}#g' pkg-message > \
	  ${PKGMESSAGE}

pre-build:
.if !defined(BATCH)
	@ ${ECHO_MSG} "-------------------------------------------------------"
	@ ${ECHO_MSG} "  If you're using an alternative MTA (not Sendmail),"
	@ ${ECHO_MSG} "  you may have to set MAIL_GID to the gid under which"
	@ ${ECHO_MSG} "  your MTA is executing."
	@ ${ECHO_MSG} "-------------------------------------------------------"
.endif

post-install:
	@${CHOWN} -R :${USERNAME} ${MAILMANDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in BUGS FAQ INSTALL NEWS README* UPGRADING
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
