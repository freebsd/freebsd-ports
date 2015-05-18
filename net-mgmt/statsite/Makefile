# $FreeBSD$

PORTNAME=	statsite
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	rbarabas@rbarabas.info
COMMENT=	C implementation of statsd

LICENSE=	BSD3CLAUSE

USES=		scons
USE_GITHUB=	yes
GH_ACCOUNT=	armon

USERS=		statsd
GROUPS=		statsd

PLIST_FILES=	bin/statsite

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/statsite ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
