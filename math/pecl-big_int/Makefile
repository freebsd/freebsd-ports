# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	big_int
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	math devel pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Functions for calculations with arbitrary length integers and bitsets

LICENSE=	BIG_INT
LICENSE_NAME=	BIG_INT license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		php:pecl
IGNORE_WITH_PHP=	70 71

CONFIGURE_ARGS=	--enable-big-int=shared

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in CREDITS README docs/index.html libbig_int/CREDITS
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for test in bitset.php example.php rand.php RSA.php std_header.php
	${INSTALL_DATA} ${WRKSRC}/tests/${test} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
