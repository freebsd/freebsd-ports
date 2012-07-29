# ex:ts=8
# New ports collection makefile for:	stan
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	stan
PORTVERSION=	0.4.1
CATEGORIES=	misc
MASTER_SITES=	http://www.roqe.org/stan/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate several statistical informations of a stream

GNU_CONFIGURE=	yes

MAN1=		stan.1
PLIST_FILES=	bin/stan

pre-configure:
	${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS ?=|g" \
	${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
