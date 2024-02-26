PORTNAME=	x2x
PORTVERSION=	1.30.20180709
PORTREVISION=	1
CATEGORIES=	x11-servers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to link multiple X servers together
WWW=		https://github.com/dottedmag/x2x

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dottedmag
GH_TAGNAME=	e62a535
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_XORG=	x11 xext xtst

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

PLIST_FILES=	bin/x2x share/man/man1/x2x.1.gz

.include <bsd.port.mk>
