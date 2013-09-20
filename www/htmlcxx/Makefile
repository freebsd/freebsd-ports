# $FreeBSD$

PORTNAME=	htmlcxx
PORTVERSION=	0.85
CATEGORIES=	www textproc
MASTER_SITES=	SF

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	HTML and CSS APIs for C++

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LGPL_V2

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

USES=		iconv
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=yes

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

NO_STAGE=	yes
.include <bsd.port.mk>
