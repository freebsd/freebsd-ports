# Created by: risner@stdio.com
# $FreeBSD$

PORTNAME=	diff
PORTVERSION=	2.11
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	http://www.tribug.org/pub/tuhs/PDP-11/Distributions/ucb/2.11BSD/ \
		http://www.stdio.com/2.11BSD/
PKGNAMEPREFIX=	2bsd-
DISTNAME=	file8

MAINTAINER=	risner@stdio.com
COMMENT=	2.11BSD diff utility

CFLAGS+=	-Wno-error=return-type
EXTRACT_AFTER_ARGS=	bin/diff man/man1/diff.1
WRKSRC=		${WRKDIR}/bin/diff

MAN1=		2diff.1

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
				${WRKSRC}/../../man/man1/diff.1

.include <bsd.port.mk>
