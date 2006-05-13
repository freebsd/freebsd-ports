# New ports collection makefile for:	webresolve
# Date created:				Wed 6 Dec 2000
# Whom:					Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	webresolve
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://siag.nu/pub/webresolve/ \
		ftp://siag.nu/pub/webresolve/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Webresolve resolves IP addresses to host names in web log files

HAS_CONFIGURE=	yes

ALL_TARGET=	webresolve

MAN1=		webresolve.1 splitwr.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; s|\-g||' \
		${WRKSRC}/configure

.include <bsd.port.mk>
