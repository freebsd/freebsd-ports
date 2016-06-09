# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	templates_parser
PORTVERSION=	17.0.0
CATEGORIES=	textproc

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Web page template engine module for the Ada Web Server

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		xmlada>=4.4:textproc/xmlada
RUN_DEPENDS=	xmlada>=4.4:textproc/xmlada

USES=		ada:run gmake tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	templates-parser
GH_TAGNAME=	1d62939

DESTINC=	${STAGEDIR}${PREFIX}/include/templates_parser
PLIST_SUB=	LIBVER=${PORTVERSION:R}
MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		ENABLE_SHARED=true \
		HOST=${CONFIGURE_TARGET} \
		TARGET=${CONFIGURE_TARGET} \
		VERSION=${PORTVERSION:R} \
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/templates*

.include <bsd.port.mk>
