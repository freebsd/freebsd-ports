PORTNAME=	bicon
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bidirectional text console
WWW=		https://www.arabeyes.org/Bicon

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES=		autoreconf libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=	bin/bicon.in \
		font/bicon-bdf2psf.pl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	behdad

PORTDOCS=	AUTHORS HISTORY HISTORY.farsi NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
