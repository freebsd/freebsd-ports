# Created by: uwe.pierau@tu-clausthal.de
# $FreeBSD$

PORTNAME=	mysqlphp2postgres
PORTVERSION=	0.95
CATEGORIES=	www
MASTER_SITES=	http://downloads.mikekohn.net/mp2p/ \
		http://www.heim2.tu-clausthal.de/~upp/mysqlphp2postgres/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert MySQL calls in a PHP page into PostgreSQL calls

ALL_TARGET=	default
PLIST_FILES=	bin/mysqlphp2postgres

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
