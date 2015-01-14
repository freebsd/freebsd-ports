# $FreeBSD$

PORTNAME=	statsite
PORTVERSION=	0.6.5
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/armon/statsite/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	rbarabas@rbarabas.info
COMMENT=	C implementation of statsd

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

USERS=		statsd
GROUPS=		statsd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/statsite

do-build:
	cd ${WRKSRC} && make

do-install:
	${STRIP_CMD} ${WRKSRC}/statsite
	${CP} ${WRKSRC}/statsite ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
