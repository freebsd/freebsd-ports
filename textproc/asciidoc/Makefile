PORTNAME=	asciidoc
PORTVERSION=	10.2.0
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages

LICENSE=	GPLv2+

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl

USES=		gnome python:3.5+ shebangfix
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

SHEBANG_FILES=	asciidoc/resources/filters/*.py \
		asciidoc/resources/filters/*/*.py

.include <bsd.port.mk>
