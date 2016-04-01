# Created by: Nikola Kolev <koue@chaosophia.net>
# $FreeBSD$

PORTNAME=	graffer
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://chaosophia.net/downloads/graffer/ \
		http://ns1.chaosophia.net/downloads/graffer/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Utility to render graphical statistics

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		jpeg

PLIST_FILES=	bin/graffer \
		etc/graffer/graffer.conf.example \
		man/man8/graffer.8.gz

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/graffer.[c8]
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/graffer.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/graffer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/graffer.8 ${STAGEDIR}${PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/graffer
	${INSTALL_DATA} ${WRKSRC}/graffer.conf.example ${STAGEDIR}${PREFIX}/etc/graffer

.include <bsd.port.mk>
