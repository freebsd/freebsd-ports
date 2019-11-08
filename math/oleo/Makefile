# Created by: mr
# $FreeBSD$

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU spreadsheet for X11 and terminals

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison localbase ncurses perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --without-xlt --without-SciPlot
MAKE_ENV+=	DESTDIR=${STAGEDIR}

INFO=		oleo

OPTIONS_DEFINE=	MOTIF NLS
OPTIONS_SUB=	yes

MOTIF_LIB_DEPENDS=	libplot.so:graphics/plotutils \
			libXbae.so:x11-toolkits/xbae \
			libXmHTML.so:x11-toolkits/xmhtml
MOTIF_USES_OFF=		xorg
MOTIF_USES=		motif
MOTIF_CONFIGURE_WITH=	motif
MOTIF_USE_OFF=		XORG=xt,ice,sm

NLS_USES=		gettext
NLS_LIBS=		-lintl
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=		gettext-tools

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
