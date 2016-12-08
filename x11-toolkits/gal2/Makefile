# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gal2/Makefile,v 1.54 2007/05/23 14:37:18 ahze Exp $

PORTNAME=	gal2
PORTVERSION=	2.5.3
PORTREVISION?=	13
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME/sources/${PORTNAME:S/2$//}/2.5
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of widgets taken from GNOME 2 gnumeric

USES+=		tar:bzip2

.if !defined(REFERENCE_PORT)

USES+=		gettext gmake libtool:keepla pathfix perl5 pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnomeui libgnomeprintui
USE_XORG=	x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.6" PORTVERSION=${PORTVERSION} \
		SHLIBVERSION="2.4"

post-extract:
	${TOUCH} -f ${WRKSRC}/gal/util/e-util-private.h

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/^libutil_la_LIBADD =/s/$$/ -lm/' \
		${WRKSRC}/gal/util/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/gmacros.h|glib.h|g' \
		${WRKSRC}/gal/util/e-text-event-processor-types.h

.include <bsd.port.mk>

.endif
