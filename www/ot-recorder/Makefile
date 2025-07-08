PORTNAME=	ot-recorder
PORTVERSION=	1.0.0
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Store and access data published by OwnTracks apps
WWW=		https://github.com/owntracks/recorder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	curl>0:ftp/curl \
		libconfig>0:devel/libconfig \
		lmdb>0:databases/lmdb \
		mosquitto>0:net/mosquitto \
		pkgconf>0:devel/pkgconf

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb \
		libmosquitto.so:net/mosquitto \
		libuuid.so:misc/libuuid

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	owntracks
GH_PROJECT=	recorder

USERS=		ot-recorder
GROUPS=		ot-recorder

SUB_FILES=	ot-recorder

post-patch:
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
