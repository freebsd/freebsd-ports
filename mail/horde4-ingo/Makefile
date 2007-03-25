# Ports collection makefile for:  Ingo
# Date created:			  Dec 3, 2004
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	ingo
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	h3-
CATEGORIES=	mail www
MASTER_SITES=	HORDE

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Horde's email-filter management application

#-----------------------------------------------------------------------
# You may define this option:
#
# - WITH_SIEVE	: if you run timsieved (with Cyrus).
#
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_PHP=	imap
USE_GETTEXT=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION

PLIST_SUB=	INGODIR=${LINGODIR}  HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	INGODIR=${INGODIR}

PORTDOCS=	README CHANGES CREDITS INSTALL	\
		RELEASE_NOTES TODO
CONFFILE=	backends.php fields.php prefs.php
SUB_DIRS=	config lib locale po scripts templates themes js

LHORDEDIR?=	www/horde
LINGODIR=	${LHORDEDIR}/ingo
PEARDIR?=	${LOCALBASE}/share/pear

INGODIR=	${PREFIX}/${LINGODIR}
CONFDIR=	${INGODIR}/config

.include <bsd.port.pre.mk>

.if defined(WITH_SIEVE) || exists(${LOCALBASE}/cyrus/bin/timsieved)
RUN_DEPENDS+=	${PEARDIR}/Net/Sieve.php:${PORTSDIR}/net/pear-Net_Sieve
.endif

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/ingo:${INGODIR}:g"		\
		${FILESDIR}/httpd.conf.ingo >${WRKDIR}/httpd-ingo.conf

do-install:
	@${INSTALL} -d ${INGODIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${INGODIR}/
	@${CP} -p ${WRKSRC}/*.php ${INGODIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${INSTALL_DATA} ${WRKDIR}/httpd-ingo.conf ${HORDE_INC}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${INGODIR}/
	@${CHMOD} -R o-rwx ${CONFDIR}/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
