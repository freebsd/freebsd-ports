# New ports collection makefile for:	phalcon
# Date created:		6 May 2012
# Whom:			Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phalcon
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/c${PORTNAME}/tarball/master/
DISTNAME=	${PORTNAME}-c${PORTNAME}-${GITVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

GITVERSION=	c6df8a4
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-c${PORTNAME}-${GITVERSION}/release/

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} --with-php-config=${LOCALBASE}/bin/php-config

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

.include <bsd.port.mk>
