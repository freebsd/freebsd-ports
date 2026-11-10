PORTNAME=	libcerf
DISTVERSION=	3.9
CATEGORIES=	math
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/libcerf/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library that provides an implementation of complex error functions
WWW=		https://jugit.fz-juelich.de/mlz/libcerf/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/cerf-v${DISTVERSION}-78082a7801dae8175d95157cfd212b4f8fa327b0 # tarball directory has the commit hash

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/cerf # docs are installed with the same option and man pages
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig/|libdata/pkgconfig/|' ${WRKSRC}/cmake/installCerf.cmake

# tests as of 3.9: 100% tests passed, 0 tests failed out of 16

.include <bsd.port.mk>
