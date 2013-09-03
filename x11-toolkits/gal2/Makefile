# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gal2/Makefile,v 1.54 2007/05/23 14:37:18 ahze Exp $

PORTNAME=	gal2
PORTVERSION=	2.5.3
PORTREVISION?=	10
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.5
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of widgets taken from GNOME 2 gnumeric

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USES=		pathfix gettext perl5 gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnomeui libgnomeprintui ltverhack
USE_XORG=	x11
USE_LDCONFIG=	yes
USE_AUTOTOOLS=  libtool
CONFIGURE_ARGS=	--enable-static --with-libiconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="2.6" PORTVERSION=${PORTVERSION} \
		SHLIBVERSION="2.4"

post-extract:
	${TOUCH} -f ${WRKSRC}/gal/util/e-util-private.h

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/gmacros.h|glib.h|g' \
		${WRKSRC}/gal/util/e-text-event-processor-types.h

.include <bsd.port.mk>

.endif
