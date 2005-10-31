# Ports collection makefile for:	NetSED
# Date created:				Jan 9 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	netsed
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://dione.ids.pl/~lcamtuf/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Alters the contents of packets in real-time

MAKE_ARGS=	CFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
