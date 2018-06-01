# Created by: chinsan
# $FreeBSD$

PORTNAME=	cairo-clock
PORTVERSION=	0.3.4
PORTREVISION=	4
CATEGORIES=	x11-clocks net gnome
MASTER_SITES=	http://macslow.thepimp.net/projects/cairo-clock/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MacSlow's Cairo-Clock

USE_GNOME=	gtk20 intlhack libglade2 librsvg2
USES=		pathfix iconv gmake localbase:ldflags pkgconfig gettext
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${GZIP_CMD} -d ${WRKSRC}/man/cairo-clock.1.gz
	@${REINPLACE_CMD} -e 's,.gz,,; s,datadir)\/man,prefix)\/man,' \
		${WRKSRC}/man/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's,--export-dynamic,-export-dynamic,' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
