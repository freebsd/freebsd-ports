# Ports collection makefile for:	jeta
# Date created:			Sat Feb 10, 2007
# Whom:				Beech Rintoul <beech@alaskaparadise.com>
#
# $FreeBSD$
#

PORTNAME=	jeta
PORTVERSION=	1.0
CATEGORIES=	security www
MASTER_SITES=	HORDE
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Horde wrapper around various Java SSH applets

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i.beforeJETA

PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES
CONFFILE=	prefs.php conf.xml .htaccess conf.xml.beforeJETA
SUB_DIRS=	config jar lib locale po templates themes

LHORDEDIR?=	www/horde
LJETADIR=	${LHORDEDIR}/jeta
PEARDIR?=	${LOCALBASE}/share/pear

PLIST_SUB=	JETADIR=${LJETADIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	JETADIR=${JETADIR} PORTSDIR=${PORTSDIR} CONFDIR=${CONFDIR}

JETADIR=	${PREFIX}/${LJETADIR}
CONFDIR=	${JETADIR}/config

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

do-install:
	@${INSTALL} -d ${JETADIR}/
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${JETADIR}/
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${JETADIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${JETADIR}/
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
