# Ports collection makefile for:	vacation3
# Date created:			Thu Mar 08, 2007
# Whom:				Beech Rintoul <beech@alaskaparadise.com>
#
# $FreeBSD$
#

PORTNAME=	vacation
PORTVERSION=	3.0
DISTVERSIONPREFIX=	h3-
CATEGORIES=	mail www
MASTER_SITES=	HORDE
PKGNAMEPREFIX=	horde-

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	E-mail auto-responder

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP	if you do not need OpenLDAP;
#
# - WITHOUT_FTP	disable FTP support;
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif

.if !defined(WITHOUT_FTP)
USE_PHP+=	ftp
.endif

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i ""

PORTDOCS=	CHANGES CREDITS INSTALL RELEASE_NOTES TODO
CONFFILE=	conf.xml .htaccess
SUB_DIRS=	config files lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LVACDIR=	${LHORDEDIR}/vacation
PEARDIR?=	${LOCALBASE}/share/pear

PLIST_SUB=	VACDIR=${LVACDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	VACDIR=${VACDIR} PORTSDIR=${PORTSDIR} CONFDIR=${CONFDIR}

VACDIR=		${PREFIX}/${LVACDIR}
CONFDIR=	${VACDIR}/config

HOSTNAME?=	`/bin/hostname`
SERVOS?=	${OPSYS}-${OSREL}

PORTREV_H?=	${LOCALBASE}/include/c-client/portrevision.h

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes/
.else
HORDE_INC=	${LOCALBASE}/etc/horde/
.endif

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@${REINPLACE_CMD} -e "s:/usr/local:${LOCALBASE}:" ${WRKSRC}/config/conf.xml
	@${SED} -e "s:/home/httpd/html/horde/vacation:${VACDIR}:" \
		${FILESDIR}/httpd.conf.vacation > ${WRKDIR}/httpd-vacation.conf

do-install:
	@${INSTALL} -d ${VACDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${VACDIR}/
	@${CP} -p ${WRKSRC}/*.php ${VACDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${INSTALL_DATA} ${WRKDIR}/httpd-vacation.conf ${HORDE_INC}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${VACDIR}/
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
