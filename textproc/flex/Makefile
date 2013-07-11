# $FreeBSD$

PORTNAME=	flex
PORTVERSION=	2.5.37
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man \
		gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		bison
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
# install flex header to its own dir to avoid conflict with system flex.
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/flex
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
USE_GMAKE=	yes
MAN1=		flex.1
INFO=		flex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.else
CONFIGURE_ARGS+=--docdir=${WRKSRC}
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee 's/tests//' \
		-e 's/^([[:space:]]*)\$$\(RANLIB\) ([^ ;]*)/\1chmod u+w \2;&/' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/@MAKEINFO@/& --no-split/g' \
		${WRKSRC}/doc/Makefile.in
	${RM} -f ${WRKSRC}/doc/*.info*

.include <bsd.port.mk>
