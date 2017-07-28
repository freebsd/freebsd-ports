# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	teckit
PORTVERSION=	2.5.7
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc converters

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Toolkit for converting data between 8-bit legacy encodings and Unicode

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/license/LICENSING.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	silnrsi
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS README NEWS docs/*.pdf license/LICENSING.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
