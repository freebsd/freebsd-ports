# New ports collection makefile for:	mkitalic
# Date created:		6 January 2002
# Whom:			KOMATSU Shinichiro
#
# $FreeBSD$
#

PORTNAME=	mkitalic
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
EXTRACT_SUFX=	.bz2

MAINTAINER=	koma2@jiro.c.u-tokyo.ac.jp

USE_PERL5=	yes
USE_X_PREFIX=	yes
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mkitalic
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkitalic ${PREFIX}/bin

.include <bsd.port.mk>
