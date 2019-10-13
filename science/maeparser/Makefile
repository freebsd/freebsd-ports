# $FreeBSD$

PORTNAME=	maeparser
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parser for Schrodinger Maestro files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	schrodinger
USE_LDCONFIG=	yes

.include <bsd.port.mk>
