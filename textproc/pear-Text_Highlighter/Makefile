# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	Text_Highlighter
PORTVERSION=	0.8.0
CATEGORIES=	textproc pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR Syntax highlighting

LICENSE=	PHP301

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:devel/pear-XML_Parser@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:devel/pear-XML_Parser@${PHP_FLAVOR}

USES=		pear
NO_ARCH=	yes

CONFLICTS_INSTALL=	generate julius php*-pear-Text_Highlighter # bin/generate

.include <bsd.port.mk>
