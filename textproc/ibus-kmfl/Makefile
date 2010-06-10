# New ports collection makefile for:	ibus-kmfl
# Date created:		4 June 2010
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	ibus-kmfl
PORTVERSION=	1.0.2
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL IMEngine for IBus framework

LIB_DEPENDS=	ibus.2:${PORTSDIR}/textproc/ibus \
		kmfl.0:${PORTSDIR}/textproc/libkmfl \
		kmflcomp.0:${PORTSDIR}/textproc/kmflcomp
RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

USE_GNOME=	glib20 pkgconfig

USE_AUTOTOOLS=	aclocal:110 automake:110
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing --copy
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' \
		${WRKSRC}/src/kmflutil.c ${WRKSRC}/src/kmfl.xml.in.in

.include <bsd.port.mk>
