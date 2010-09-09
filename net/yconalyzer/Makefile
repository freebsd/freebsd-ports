# New ports collection makefile for:	yconalyzer
# Date created:		2010-09-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	yconalyzer
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	TCP Traffic Analyzer

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/yconalyzer
USE_BZIP2=	yes
USE_GMAKE=	yes

MAN8=		yconalyzer.8

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
