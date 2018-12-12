# $FreeBSD$

PORTNAME=	xmlf90
DISTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://launchpad.net/xmlf90/trunk/1.5/+download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of light-weight libraries to work with XML in Fortran

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	fox-xml

USES=		fortran gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
