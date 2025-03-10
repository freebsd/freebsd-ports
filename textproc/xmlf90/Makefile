PORTNAME=	xmlf90
DISTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://gitlab.com/-/project/12146849/uploads/8153db06dece1c0b9c38dcda31918fbf/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of light-weight libraries to work with XML in Fortran
WWW=		https://gitlab.com/siesta-project/libraries/xmlf90

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	fox-xml # see https://gitlab.com/siesta-project/libraries/xmlf90/-/issues/8

USES=		cmake fortran pathfix
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
