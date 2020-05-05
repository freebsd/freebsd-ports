# $FreeBSD$

PORTNAME=	jitsi
PORTVERSION=	1.0.4048
PORTREVISION=	1
CATEGORIES=	www net-im
MASTER_SITES=	https://download.jitsi.org/jitsi-meet/src/
DISTVERSIONPREFIX=	meet-
PKGNAMESUFFIX=	-meet

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Secure, Simple and Scalable Video Conferences

LICENSE=	APACHE20

USES=		tar:bzip2
NO_BUILD=	yes

SUB_FILES+=	pkg-message

WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}

post-extract:
	@${MV} ${WRKSRC}/config.js ${WRKSRC}/config.js.sample
	@${MV} ${WRKSRC}/interface_config.js ${WRKSRC}/interface_config.js.sample

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
