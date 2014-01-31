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
USE_BZIP2=	yes
USES=		gmake

PLIST_FILES=	bin/yconalyzer \
		man/man8/yconalyzer.8.gz

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
