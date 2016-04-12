# Created by: mr
# $FreeBSD$

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU spreadsheet for X11 and terminals

LICENSE=	GPLv2

USES=		bison perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --without-xlt --without-SciPlot
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl
MAKE_ENV+=	DESTDIR=${STAGEDIR}

INFO=		oleo

OPTIONS_DEFINE=	MOTIF NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOTIF}
LIB_DEPENDS+=	libplot.so:graphics/plotutils \
		libXbae.so:x11-toolkits/xbae \
		libXmHTML.so:x11-toolkits/xmhtml
USES+=		motif
CONFIGURE_ARGS+=	--with-motif
.else
USE_XORG=	xt ice sm
CONFIGURE_ARGS+=	--without-motif
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${REINPLACE_CMD} -e '/^DESTDIR/s|=|?=|' \
	    ${WRKSRC}/Makefile.in
.for pof in en fr nl
	@${REINPLACE_CMD} -e "s|CHARSET|ISO-8859-1|;s|ENCODING|8bit|"	\
		${WRKSRC}/po/${pof}.po
.endfor
	@${REINPLACE_CMD} -e "s|am: install-docDATA|am:|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-info-am install-htmlDATA|install-info-am|" \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
