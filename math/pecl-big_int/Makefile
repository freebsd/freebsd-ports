# Ports collection makefile for:	pecl-big_int
# Date created:				16 May 2005
# Whom:					Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	big_int
PORTVERSION=	1.0.7
CATEGORIES=	math devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Functions for calculations with arbitrary length integers and bitsets

USE_PHP=	yes
USE_PHPEXT=	yes

DOCS=		CREDITS INSTALL LICENSE README docs/index.html libbig_int/CREDITS \
		libbig_int/LICENSE
EXAMPLES=	bitset.php example.php rand.php RSA.php std_header.php

CONFIGURE_ARGS=	--enable-big-int=shared

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
.  for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.  endfor
.  for test in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tests/${test} ${EXAMPLESDIR}
.  endfor
.endif

.include <bsd.port.mk>
