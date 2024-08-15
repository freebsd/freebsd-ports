PORTNAME=	libwbxml
PORTVERSION=	0.11.8
DISTVERSIONPREFIX=	libwbxml-
CATEGORIES=	textproc devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library & tools for converting wbxml<->xml
WWW=		http://libwbxml.opensync.org/ \
		https://github.com/libwbxml/libwbxml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake iconv tar:bzip2
USE_LDCONFIG=	yes

USE_GITHUB=	yes

DOCSDIR=	${PREFIX}/share/doc/libwbxml

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in BUGS ChangeLog README References THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
