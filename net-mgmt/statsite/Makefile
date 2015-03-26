# $FreeBSD$

PORTNAME=	statsite
PORTVERSION=	0.7.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/armon/statsite/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	rbarabas@rbarabas.info
COMMENT=	C implementation of statsd

LICENSE=	BSD3CLAUSE

USES=		scons

USERS=		statsd
GROUPS=		statsd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/statsite

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/statsite ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
