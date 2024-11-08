PORTNAME=	ipgen
PORTVERSION=	1.30.20240527
CATEGORIES=	net-mgmt

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Interactive Packet Generator and Benchmarking Utility
WWW=		https://github.com/iij/ipgen

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	iij
GH_TAGNAME=	9e649f4

SHEBANG_FILES=	gen/layout_generator
MAKEFILE=	GNUmakefile
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f ${MAKEFILE} depend
pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
