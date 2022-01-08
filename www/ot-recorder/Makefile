# Created by: tundra

PORTNAME=	ot-recorder
PORTVERSION=	0.8.4
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Store and access data published by OwnTracks apps

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

SUB_FILES=	ot-recorder

LIB_DEPENDS+=	libcurl.so:ftp/curl
LIB_DEPENDS+=	libconfig.so:devel/libconfig
LIB_DEPENDS+=	liblmdb.so:databases/lmdb
LIB_DEPENDS+=	libmosquitto.so:net/mosquitto

USE_GITHUB=	yes
GH_ACCOUNT=	owntracks
GH_PROJECT=	recorder

USERS=		ot-recorder
GROUPS=		ot-recorder

pre-patch:
	${CP} ${WRKSRC}/config.mk.in ${WRKSRC}/config.mk

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocat        ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ot-recorder ${STAGEDIR}${PREFIX}/sbin

	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/docroot && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/)

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/ot-recorder.default ${STAGEDIR}${ETCDIR}/ot-recorder.conf.sample

	${MKDIR} ${STAGEDIR}/var/log/ot-recorder
	${MKDIR} ${STAGEDIR}/var/db/owntracks
	${MKDIR} ${STAGEDIR}/var/db/owntracks/recorder
	${MKDIR} ${STAGEDIR}/var/run/ot-recorder

	${INSTALL_SCRIPT} ${WRKDIR}/ot-recorder ${STAGEDIR}$/${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
