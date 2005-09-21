# New ports collection makefile for:    evidence
# Date created:                31 Juli 2005
# Whom:                    Anders Troback
#
# $FreeBSD$
#

PORTNAME=	evidence
PORTVERSION=	0.9.8
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@troback.com
COMMENT=	Enlightened file-manager

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		evas.1:${PORTSDIR}/graphics/evas \
		edje.5:${PORTSDIR}/graphics/edje \
		ecore.1:${PORTSDIR}/x11/ecore \
		embryo.9:${PORTSDIR}/lang/embryo \
		eet.9:${PORTSDIR}/devel/eet \
		xine.14:${PORTSDIR}/multimedia/libxine

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--disable-thumbnailer-xine \
		--disable-plugin-vorbis \
		--disable-plugin-id3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=	evidence.1
INFO=	evidence

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Broken dependencies."
.endif

.include <bsd.port.post.mk>
