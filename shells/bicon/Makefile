# Created by: Carlos Jacobo Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bicon
PORTVERSION=	0.5
CATEGORIES=	shells

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bidirectional text console

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES=		autoreconf libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=	bin/bicon.in \
		font/bicon-bdf2psf.pl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	behdad

PORTDOCS=	AUTHORS HISTORY HISTORY.farsi NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
