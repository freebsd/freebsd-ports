# Ports collection makefile for:	ah-tty
# Date created:				Tue Jun 25, 2002
# Whom:			Michael L. Hostbaek <mich@freebsdcluster.org>
#
# $FreeBSD$
#

PORTNAME=	ah-tty
PORTVERSION=	0.3.12
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Ah-tty is an automatic helper for command prompts and shells

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ah-tty bin/ah-tty.static share/ah-tty.conf

MAN1=		ah-tty.1
INFO=		ah-tty

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/dillib/vty/vtlabel.c
	@${REINPLACE_CMD} -e 's|##x|x|' \
		${WRKSRC}/include/platform.h

.include <bsd.port.mk>
