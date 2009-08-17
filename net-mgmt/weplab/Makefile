# New ports collection makefile for:	weplab
# Date created:				24 Aug 2006
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	weplab
PORTVERSION=	0.1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WepLab is a tool designed to teach how WEP works

GNU_CONFIGURE=	yes

MAN1=		weplab.1
PLIST_FILES=	bin/weplab

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS|LDFLAGS) *=,\1 ?=,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
