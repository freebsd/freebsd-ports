PORTNAME=	NymphCastLib
DISTVERSION=	v0.1-rc0
CATEGORIES=	multimedia

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Core functionality for a NymphCast client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnymphrpc.so:multimedia/nymphrpc \
		libPocoNet.so:devel/poco

USES=		compiler:c++17-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	MayaPosch
GH_PROJECT=	libnymphcast

.include <bsd.port.mk>
