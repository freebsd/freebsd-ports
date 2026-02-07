PORTNAME=	html2xhtml
DISTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.it.uc3m.es/jaf/html2xhtml/downloads/

MAINTAINER=	wilfried.meindl@gmail.com
COMMENT=	Convert HTML to XHTML
WWW=		https://www.it.uc3m.es/jaf/html2xhtml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	p5-HTML-HTML5-Parser p5-XML-Driver-HTML # bin/html2xhtml

PLIST_FILES=	bin/dtdquery \
		bin/html2xhtml \
		share/man/man1/html2xhtml.1.gz

.include <bsd.port.mk>
