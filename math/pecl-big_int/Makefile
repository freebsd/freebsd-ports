# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	big_int
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	math devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Functions for calculations with arbitrary length integers and bitsets

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

DOCS=		CREDITS INSTALL LICENSE README docs/index.html libbig_int/CREDITS \
		libbig_int/LICENSE
EXAMPLES=	bitset.php example.php rand.php RSA.php std_header.php

CONFIGURE_ARGS=	--enable-big-int=shared

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.  for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.  endfor
.  for test in ${STAGEDIR}${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tests/${test} ${STAGEDIR}${EXAMPLESDIR}
.  endfor

.include <bsd.port.mk>
