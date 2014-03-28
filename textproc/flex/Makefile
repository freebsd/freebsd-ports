# $FreeBSD$

PORTNAME=	flex
PORTVERSION=	2.5.39
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man \
		gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		bison gmake tar:bzip2
GNU_CONFIGURE=	yes
# install flex header to its own dir to avoid conflict with system flex.
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/flex --disable-shared
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
INSTALL_TARGET=	install-strip

INFO=		flex

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee 's/tests//' \
		-e 's/^([[:space:]]*)\$$\(RANLIB\) ([^ ;]*)/\1chmod u+w \2;&/' \
		-e '/echo.*RANLIB/,+1d' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/@MAKEINFO@/& --no-split/g' \
		${WRKSRC}/doc/Makefile.in
	${RM} -f ${WRKSRC}/doc/*.info*

.include <bsd.port.mk>
