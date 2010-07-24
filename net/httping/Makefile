# New ports collection makefile for:	httping
# Date created:				26 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	httping
PORTVERSION=	1.4.4
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A ping-like tool for HTTP requests

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		httping.1
PLIST_FILES=	bin/httping

.include <bsd.port.pre.mk>

.if(${OSVERSION} >= 701101)
CFLAGS+=	-D_GNU_SOURCE
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
