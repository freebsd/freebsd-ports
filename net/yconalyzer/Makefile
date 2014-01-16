# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	yconalyzer
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	TCP Traffic Analyzer

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/yconalyzer
USE_BZIP2=	yes
USE_GMAKE=	yes
NO_STAGE=	yes

MAN8=		yconalyzer.8

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
