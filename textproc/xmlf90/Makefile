PORTNAME=	xmlf90
DISTVERSION=	1.5.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://gitlab.com/siesta-project/libraries/xmlf90/-/archive/1.5.5/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of light-weight libraries to work with XML in Fortran
WWW=		https://launchpad.net/xmlf90

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	fox-xml

USES=		autoreconf fortran gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
