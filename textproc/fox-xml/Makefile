PORTNAME=	fox
DISTVERSION=	4.1.2-91
PORTREVISION=	4
DISTVERSIONSUFFIX=	-g9c6716e
CATEGORIES=	textproc
PKGNAMESUFFIX=	-xml

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fortran XML library
WWW=		https://homepages.see.leeds.ac.uk/~earawa/FoX/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	xmlf90

GNU_CONFIGURE=	yes
USES=		fortran gmake
USE_GITHUB=	yes
GH_ACCOUNT=	andreww
ALL_TARGET=	default

.include <bsd.port.mk>
