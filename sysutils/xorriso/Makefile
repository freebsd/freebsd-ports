# New ports collection makefile for:	libisoburn
# Date created:		2008 November 13
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	xorriso
PORTVERSION=	0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	libisoburn
DISTFILES=	${DISTNAME}-${PORTVERSION}.pl01${EXTRACT_SUFX}

MAINTAINER=	fbsd@opal.com
COMMENT=	ISO image manipulation tool based on Libburnia

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	burn.4:${PORTSDIR}/devel/libburn \
		isofs.6:${PORTSDIR}/devel/libisofs

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-lcam -L${PREFIX}/lib -liconv"

WANT_GNOME=	yes
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

MAN1=		xorriso.1

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|;' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
