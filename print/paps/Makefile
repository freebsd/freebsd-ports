# Created by: johans
# $FreeBSD$

PORTNAME=	paps
PORTVERSION=	0.6.8
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	UTF-8 to PostScript converter using Pango

PLIST_FILES=	bin/paps lib/libpaps.a include/libpaps.h \
		man/man1/paps.1.gz

GNU_CONFIGURE=	yes
USE_GNOME=	pango
USES=		pkgconfig

post-patch:
	@${REINPLACE_CMD} -e '/echo.*RANLIB/,+1d' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
