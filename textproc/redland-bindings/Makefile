PORTNAME=	redland-bindings
PORTVERSION=	1.0.17.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Language bindings for the Redland package

# Even though GPLv3 is not explicitly mentioned in the port's LICENSE.html, one
# of its licenses is "GPLv2 or newer", which includes GPLv3.
LICENSE=	APACHE20 GPLv2 GPLv3 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	librdf.so:textproc/redland

GNU_CONFIGURE=	yes
USES=		pkgconfig

OPTIONS_DEFINE=	PHP PYTHON RUBY
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PHP_CONFIGURE_WITH=	php
PHP_USES=		php:build
PYTHON_CONFIGURE_WITH=	python
PYTHON_USES=		python
RUBY_CONFIGURE_WITH=	ruby
RUBY_USE=		RUBY=yes

.include <bsd.port.mk>
