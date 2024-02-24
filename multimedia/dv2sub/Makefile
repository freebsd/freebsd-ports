PORTNAME=	dv2sub
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	oz@nixil.net
COMMENT=	Extracts info or subtitles from DV stream
WWW=		https://dv2sub.sourceforge.net/

LIB_DEPENDS=	libdv.so:multimedia/libdv

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		pkgconfig

PLIST_FILES=	bin/dv2sub share/man/man1/dv2sub.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/void foo(void)//' ${WRKSRC}/configure

.include <bsd.port.mk>
