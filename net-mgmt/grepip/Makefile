# New ports collection makefile for:	grepip
# Date created:		2 Nov 2005
# Whom:			Serge Maslov <serge@maslov.biz>
#
# $FreeBSD$
#

PORTNAME=	grepip
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/lexa/ \
		ftp://ftp.des.tstu.ru/pub/mirror/Unix/apache/apache.lexa.ru/pub/domestic/lexa/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print lines contans IP matching a pattern in CIDR format

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

PLIST_FILES=	bin/grepip
PORTDOCS=	README.txt

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -c patricia.c; \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -o grepip grepip.c patricia.o -L${LOCALBASE}/lib -lpcre

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/grepip ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
