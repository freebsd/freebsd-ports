# Created by: chinsan
# $FreeBSD$

PORTNAME=	cairo-clock
PORTVERSION=	0.3.4
PORTREVISION=	2
CATEGORIES=	x11-clocks net gnome
MASTER_SITES=	http://macslow.thepimp.net/projects/cairo-clock/

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	MacSlow's Cairo-Clock

USE_GNOME=	gtk20 intlhack libglade2 librsvg2
USES=		pathfix iconv gmake pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN1=		cairo-clock.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${GZIP_CMD} -d ${WRKSRC}/man/cairo-clock.1.gz
	@${REINPLACE_CMD} -e 's,.gz,,; s,datadir)\/man,prefix)\/man,' \
		${WRKSRC}/man/Makefile.in

post-configure:
.if ${OSVERSION} > 1000000 || ${CC:Mclang} != ""
	@${REINPLACE_CMD} -e 's,--export-dynamic,-export-dynamic,' \
		${WRKSRC}/src/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in README NEWS AUTHORS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${ECHO} ""
	@${ECHO} "************************************************************************"
	@${ECHO} " Please note that you need composite extension enabled in X.org or Xgl. "
	@${ECHO} "************************************************************************"

.include <bsd.port.mk>
