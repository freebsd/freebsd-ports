# New ports collection makefile for:	pstack
# Date created:		1 May 2002
# Whom:			Peter Edwards <pmedwards@eircom.net>
#
# $FreeBSD$
# $Id: Makefile,v 1.2 2002/11/26 10:38:28 pmedwards Exp $
#

PORTNAME=	pstack
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/bsd-${PORTNAME}/bsd-${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Retrieve process/core file stack traces

ONLY_FOR_ARCHS=	i386

MANCOMPRESSED=	yes
MAN1=		pstack.1
PLIST_FILES=	bin/pstack

post-patch:
	${REINPLACE_CMD} -e 's/DT_COUNT/DT_BIND_NOW/' ${WRKSRC}/elf.c

.include <bsd.port.mk>
