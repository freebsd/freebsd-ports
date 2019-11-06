# Created by: Maciek Korzen <eaquer@ceti.pl>
# $FreeBSD$

PORTNAME=	tleenx2
PORTVERSION=	20040214
PORTREVISION=	11
CATEGORIES=	polish net
MASTER_SITES=	SF/tleenx/tleenx2/${DISTNAME}
DISTNAME=	TleenX2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client for polish IM service called Tlen.pl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtlen.so:polish/libtlen

USES=		gnome localbase:ldflags pkgconfig xorg
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_XORG=	x11 xscrnsaver
WRKSRC=		${WRKDIR}/TleenX2-${PORTVERSION}

PORTDOCS=	README gg.txt sms.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e '/^tleenx2_LDADD =/,+1s,/usr/X11R6/lib/libXss.a,-lXss -lX11,' \
		-e 's,/usr/X11R6/lib/libXss.a,,' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},g; s,gcc,${CC},' \
		${WRKSRC}/iksemel/Makefile
	@${REINPLACE_CMD} 's,gcc,${CC},' ${WRKSRC}/jabby/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
