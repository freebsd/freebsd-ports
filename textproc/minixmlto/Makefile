PORTNAME=	minixmlto
PORTVERSION=	0.0.6
CATEGORIES=	textproc

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimalistic alternative to xmlto
WWW=		https://github.com/bapt/minixmlto

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt \
		html2text:textproc/html2text

USE_GITHUB=	yes
GH_ACCOUNT=	bapt
PLIST_FILES=	bin/minixmlto
MAKE_ARGS=	DOCBOOK_XSL="${LOCALBASE}/share/xsl/docbook" PREFIX="${PREFIX}"
NO_ARCH=	yes

.include <bsd.port.mk>
