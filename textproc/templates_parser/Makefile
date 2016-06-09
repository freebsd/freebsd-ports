# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	templates_parser
PORTVERSION=	11.10.0.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Web page template engine module for the Ada Web Server

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		xmlada>=4.4:textproc/xmlada
RUN_DEPENDS=	xmlada>=4.4:textproc/xmlada

USES=		ada gmake tar:bzip2
DESTINC=	${STAGEDIR}${PREFIX}/include/templates_parser
PLIST_SUB=	LIBVER=11.10.0w
MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		ENABLE_SHARED=true \
		HOST=${CONFIGURE_TARGET} \
		TARGET=${CONFIGURE_TARGET} \
		prefix=${PREFIX}

PORTDOCS=	html

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

do-build:
	# Override build target to avoid -jX getting passed to makefile
	# Parallel builds are handled with PROCESSORS setting
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} build

do-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} html

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/gpr/manifests
	${MV} ${DESTINC}.relocatable/templates_parser-conf*.ads \
		${DESTINC}.relocatable/templates_parser-configuration.ads
	${MV} ${DESTINC}/templates_parser-conf*.ads \
		${DESTINC}/templates_parser-configuration.ads
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${FILESDIR}/templates_parser.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
