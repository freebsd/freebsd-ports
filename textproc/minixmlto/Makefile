# $FreeBSD$

PORTNAME=	minixmlto
PORTVERSION=	0.0.3
CATEGORIES=	textproc

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimalistic alternative to xmlto

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt \
		html2text:textproc/html2text

USE_GITHUB=	yes
GH_ACCOUNT=	bapt
PLIST_FILES=	bin/minixmlto
MAKE_ARGS=	DOCBOOK_XSL="${LOCALBASE}/share/xsl/docbook" PREFIX="${PREFIX}"

.include <bsd.port.mk>
