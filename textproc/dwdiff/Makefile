# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	dwdiff
PORTVERSION=	2.0.4
CATEGORIES=	textproc
MASTER_SITES=	http://os.ghalkes.nl/dist/ \
 		http://fossies.org/unix/privat/ \
		LOCAL/avl
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Delimited word diff program

LICENSE=	GPLv3

OPTIONS_DEFINE=	UNICODE NLS DOCS
OPTIONS_DEFAULT=UNICODE


HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man

MAN1=		${PORTNAME}.1 dwfilter.1
PORTDOCS=	COPYING Changelog README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
MANLANG=	"" nl nl.UTF-8
.else
CONFIGURE_ARGS+=	--without-gettext
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MUNICODE}
LIB_DEPENDS+=	icudata:${PORTSDIR}/devel/icu
.else
CONFIGURE_ARGS+=	--without-unicode
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|share/doc/${PORTNAME}-${PORTVERSION}|${DOCSDIR_REL}|' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
