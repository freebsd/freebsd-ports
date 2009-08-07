# New ports collection makefile for:    m17n-im-config
# Date created:		1 October 2008
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	m17n-im-config
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.m17n.org/common/im-config/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	A GUI for per-user configuration of m17n-lib input methods

LIB_DEPENDS=	m17n.3:${PORTSDIR}/devel/m17n-lib

MAKE_JOBS_UNSAFE=	yes

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk20 intltool intlhack pkgconfig glib20
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^pkgconfigdir = $${libdir}/pkgconfig|pkgconfigdir = $${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
