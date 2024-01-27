PORTNAME=	jitsi
PORTVERSION=	1.0.7762
DISTVERSIONPREFIX=	meet-
CATEGORIES=	www net-im
MASTER_SITES=	https://download.jitsi.org/jitsi-meet/src/
PKGNAMESUFFIX=	-meet

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Secure, Simple and Scalable Video Conferences
WWW=		https://github.com/jitsi/jitsi-meet

LICENSE=	APACHE20

USES=		cpe tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

CPE_VENDOR=	jitsi
CPE_PRODUCT=	meet

SUB_FILES+=	pkg-message

WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}

post-extract:
	@${MV} ${WRKSRC}/config.js ${WRKSRC}/config.js.sample
	@${MV} ${WRKSRC}/interface_config.js ${WRKSRC}/interface_config.js.sample
	${INSTALL_DATA} ${FILESDIR}/nginx.conf.in \
		${WRKDIR}/nginx.conf
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKDIR}/nginx.conf

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/nginx.conf \
		${STAGEDIR}${EXAMPLESDIR}/nginx.conf

.include <bsd.port.mk>
