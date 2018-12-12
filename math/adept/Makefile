# $FreeBSD$

PORTNAME=	adept
DISTVERSION=	2.0.5
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.met.reading.ac.uk/clouds/adept/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Combined array and automatic differentiation library in C++

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake fortran blaslapack:openblas libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PDFTEXDOCS
PDFTEXDOCS_DESC=	Build and install PDF documentation from LaTeX sources
OPTIONS_SUB=	yes

PDFTEXDOCS_USE=	TEX=pdftex:build,dvipsk:build

post-build-PDFTEXDOCS-on:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

post-install-PDFTEXDOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
