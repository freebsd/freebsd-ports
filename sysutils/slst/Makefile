# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	slst
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/slst/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates syslog statistics to detect tendencies and unexpected change

ALL_TARGET=	all

PLIST_FILES=	bin/slst

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slst

.include <bsd.port.mk>
