# New ports collection makefile for:   guile-gtk
# Date created:        1 January 2000
# Whom:                Matt Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	guile-gtk
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	x11-toolkits scheme
#MASTER_SITES=	${MASTER_SITE_SAVANNAH}
#MASTER_SITE_SUBDIR=	${PORTNAME}
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw
DISTNAME=	${PORTNAME}-1.2-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Guile binding library for GTK+

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gnometarget
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|gtk-1\.2/||g'

.include <bsd.port.mk>
