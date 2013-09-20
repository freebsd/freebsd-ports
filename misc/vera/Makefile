# Created by: Dima Sivachenko	<dima@chg.ru>
# $FreeBSD$

PORTNAME=	vera
PORTVERSION=	1.17
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vera

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Virtual Entity of Relevant Acronyms

INFO=		vera
LICENSE=	GFDL

NO_STAGE=	yes
do-build:
	@ cd ${WRKSRC} && makeinfo --no-split vera.texi

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/vera.info ${PREFIX}/info

.include <bsd.port.mk>
