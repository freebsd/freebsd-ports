# Created by: grog
# $FreeBSD$

PORTNAME=	x2x
PORTVERSION=	1.30.20180709
CATEGORIES=	x11-servers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to link multiple X servers together

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dottedmag
GH_TAGNAME=	e62a535
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xtst

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

PLIST_FILES=	bin/x2x man/man1/x2x.1.gz

.include <bsd.port.mk>
