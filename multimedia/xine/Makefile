# New ports collection makefile for:    xine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	http://xine.sourceforge.net/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-ui-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

LIB_DEPENDS=	xine.0:${PORTSDIR}/graphics/libxine \
		aa.1:${PORTSDIR}/graphics/aalib \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-w32-path=${LOCALBASE}/lib/win32

MANLANG=	"" fr pl
MAN1=		aaxine.1 xine.1

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
	@${CP} ${PREFIX}/man/man1/aaxine.1 ${PREFIX}/man/fr/man1/aaxine.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
