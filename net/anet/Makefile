# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anet
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libanet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Networking library for Ada

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

USES=		ada tar:bzip2
ALL_TARGET=	build_lib
MAKE_ARGS+=	NUM_CPUS=${MAKE_JOBS_NUMBER} \
		LIBRARY_KIND=static \
		OS=bsd

OPTIONS_DEFINE=	TEST DOCS
TEST_DESC=		Run unit test suite before installation
TEST_ALL_TARGET=	tests
TEST_BUILD_DEPENDS=	${LOCALBASE}/lib/gnat/ahven.gpr:devel/ahven
DOCS_USES=		gmake
DOCS_ALL_TARGET=	doc
DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			source-highlight:textproc/source-highlight

post-patch:
	@${REINPLACE_CMD} -e 's|dynamic|static|g' \
		${WRKSRC}/gnat/anet.gpr
	@${REINPLACE_CMD} -e 's|DESTDIR|DEST2|g' \
		${WRKSRC}/doc/Makefile

do-build:
	@${MKDIR} ${WRKSRC}/doc/html
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/anet \
		${STAGEDIR}${PREFIX}/include/anet
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] ${WRKSRC}/src/bsd/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/anet
	${INSTALL_DATA} ${WRKSRC}/lib/bsd/static/*.ali \
		${STAGEDIR}${PREFIX}/lib/anet
	${INSTALL_DATA} ${WRKSRC}/lib/bsd/static/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gnat/anet.gpr ${STAGEDIR}${PREFIX}/lib/gnat

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
