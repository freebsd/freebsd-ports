# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	recoverdm
PORTVERSION=	0.20
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/recoverdm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recover files and discs with damaged sectors

LICENSE=	GPLv2

BROKEN=		unfetchable

PLIST_FILES=	bin/mergebad bin/recoverdm man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
