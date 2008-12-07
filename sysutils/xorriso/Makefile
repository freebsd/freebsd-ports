# New ports collection makefile for:	libisoburn
# Date created:		2008 November 13
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	libisoburn
PORTVERSION=	0.2.8
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTFILES=	${PORTNAME}-${PORTVERSION}.pl00${EXTRACT_SUFX}

MAINTAINER=	fbsd@opal.com
COMMENT=	ISO image manipulation tool based on Libburnia

LIB_DEPENDS=	burn.23:${PORTSDIR}/devel/libburn \
		isofs.12:${PORTSDIR}/devel/libisofs

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
