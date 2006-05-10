# ex:ts=8
# Ports collection makefile for:	GOPchop
# Date created:				Apr 24, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gopchop
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://outflux.net/unix/software/GOPchop/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GOPchop-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG2 GOP-accurate editor

LIB_DEPENDS=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2

USE_GNOME=	gnometarget gtk12 intlhack
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-sdl

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pixmaps/\$${PACKAGE}|\$${PACKAGE}|g ; \
		 s| -mcpu=.*"|"|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|pixmaps/\$$(PACKAGE)|\$$(PACKAGE)/pixmaps|g ; \
		 s|-lglib||g'

.include <bsd.port.mk>
