# New ports collection makefile for:	oleo
# Date created:		3 September 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU spreadsheet for X11 and terminals

USE_PERL5_BUILD=	yes
USE_BISON=	yes
USE_AUTOTOOLS=	autoconf:213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-x --without-xlt --without-SciPlot

INFO=		oleo
PORTDOCS=	AUTHORS FAQ

OPTIONS=	MOTIF "Motif support" off \
		NLS "NLS support" on

.include <bsd.port.pre.mk>

.if defined(WITH_MOTIF)
LIB_DEPENDS+=	plot:${PORTSDIR}/graphics/plotutils \
		Xbae:${PORTSDIR}/x11-toolkits/xbae \
		XmHTML:${PORTSDIR}/x11-toolkits/xmhtml
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-motif
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=	--without-motif
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
.for pof in en fr nl
	@${REINPLACE_CMD} -e "s|CHARSET|ISO-8859-1|;s|ENCODING|8bit|"	\
		${WRKSRC}/po/${pof}.po
.endfor
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|am: install-docDATA|am:|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-info-am install-htmlDATA|install-info-am|" \
		${WRKSRC}/doc/Makefile.in
.endif

pre-build:
.for file in src/io-term.c
	cd ${WRKSRC} && ${MV} ${file} ${file}.pre_iconv \
		&& iconv -c -t ascii ${file}.pre_iconv > ${file} || ${TRUE}
.endfor

.include <bsd.port.post.mk>
