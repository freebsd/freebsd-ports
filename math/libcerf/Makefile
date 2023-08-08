PORTNAME=	libcerf
DISTVERSION=	2.3
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

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/cerf # docs are installed with the same option and man pages
PORTDOCS=	*

.include <bsd.port.mk>
