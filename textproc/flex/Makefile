# $FreeBSD$

PORTNAME=	flex
PORTVERSION=	2.6.1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/westes/flex/releases/download/v${PORTVERSION}/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

BUILD_DEPENDS=	help2man:misc/help2man \
		gm4:devel/m4
RUN_DEPENDS=	gm4:devel/m4

USES=		bison gmake libtool makeinfo tar:xz
GNU_CONFIGURE=	yes
# install flex header to its own dir to avoid conflict with system flex.
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/flex --disable-shared
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4 MAKEINFO="makeinfo --no-split"
INSTALL_TARGET=	install-strip

INFO=		flex
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee 's/tests//' \
		-e '/mode=compile ..CC/s/\\$$/-fPIC -DPIC &/' \
		${WRKSRC}/Makefile.in
	${RM} -f ${WRKSRC}/doc/*.info*

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
	${RM} ${STAGEDIR}${EXAMPLESDIR}/Makefile.am
.endif

.include <bsd.port.mk>
