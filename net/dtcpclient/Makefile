# New ports collection makefile for:	dtcpclient
# Date Created:		Feb 27 2003
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dtcpclient
PORTVERSION=	20030301
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol client

MAN8=		dtcpclient.8
MANCOMPRESSED=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dtcpclient.sh \
		${PREFIX}/etc/rc.d/dtcpclient.sh.sample

.include <bsd.port.mk>
