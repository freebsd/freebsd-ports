# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mc
PORTVERSION=	4.5.55
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/mc

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses --without-gnome
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		mc.1 mcedit.1

post-patch:
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/mc|\$\(datadir\)/mc|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	@${LN} -sf mc ${PREFIX}/bin/midc

.include <bsd.port.mk>
