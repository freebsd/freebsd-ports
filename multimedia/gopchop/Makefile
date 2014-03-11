# Created by: ijliao
# $FreeBSD$

PORTNAME=	gopchop
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/GOPchop%20-%20Stable/${PORTVERSION} \
		http://outflux.net/unix/software/GOPchop/download/

DISTNAME=	GOPchop-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG2 GOP-accurate editor

LIB_DEPENDS=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_GNOME=	gtk12 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-sdl
PORTSCOUT=	skipv:1.1.0,1.1.1,1.1.2,1.1.3,1.1.4,1.1.5,1.1.6,1.1.7,1.1.8

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pixmaps/\$${PACKAGE}|\$${PACKAGE}|g ; \
		 s| -mcpu=.*"|"|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|pixmaps/\$$(PACKAGE)|\$$(PACKAGE)/pixmaps|g ; \
		 s|-lglib||g'

.include <bsd.port.mk>
