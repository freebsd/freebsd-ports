PORTNAME=	adept
DISTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.met.reading.ac.uk/clouds/adept/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Combined array and automatic differentiation library in C++
WWW=		https://www.met.reading.ac.uk/clouds/adept/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake fortran blaslapack:openblas libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		PDFTEXDOCS
OPTIONS_SUB=		yes

PDFTEXDOCS_DESC=	Build and install PDF documentation from LaTeX sources
PDFTEXDOCS_USES=	tex
PDFTEXDOCS_USE=		TEX=pdftex:build,dvipsk:build

post-build-PDFTEXDOCS-on:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

post-install-PDFTEXDOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
