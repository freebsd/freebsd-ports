# New ports collection makefile for:	libguess
# Date created:				04 May 2012
# Whom:					William Grzybowski
#
# $FreeBSD$
#

PORTNAME=	libguess
PORTVERSION=	1.1
CATEGORIES=	textproc devel
MASTER_SITES=	http://distfiles.atheme.org/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	A high-speed character set detection library

LIB_DEPENDS=	mowgli.2:${PORTSDIR}/devel/libmowgli

USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${DESTDIR}$${libdir}/pkgconfig|$${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
