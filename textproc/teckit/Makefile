# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	teckit
PORTVERSION=	2.5.1
PORTREVISION=	1
CATEGORIES=	textproc converters
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DISTNAME=	TECkit_${PORTVERSION:S|.|_|g}

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Toolkit for converting data between 8-bit legacy encodings and Unicode

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS README NEWS docs/*.pdf license/LICENSING.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	${CHMOD} ${BINMODE} ${WRKSRC}/configure ${WRKSRC}/install-sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
