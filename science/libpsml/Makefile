PORTNAME=	libpsml
DISTVERSION=	2.1.0
CATEGORIES=	science # quantum-chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to handle pseudopotentials in PSML format
WWW=		https://gitlab.com/siesta-project/libraries/libpsml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxmlf90.so:textproc/xmlf90

USES=		cmake fortran
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	siesta-project/libraries
GL_TAGNAME=	508cffb93bcb2137a64472f4d9623ba42748aaa9

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
