# New ports collection makefile for:	dtcpclient
# Date Created:		Feb 27 2003
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dtcpclient
PORTVERSION=	20090812
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol client

USE_RC_SUBR=	dtcpclient

MAN8=		dtcpclient.8
MANCOMPRESSED=	yes

pre-install:
	@if [ -f ${PREFIX}/etc/rc.d/${USE_RC_SUBR} ]; then \
		${ECHO_CMD} "Remove old ${PREFIX}/etc/rc.d/${USE_RC_SUBR} before install."; \
		exit 1; \
	fi

.include <bsd.port.mk>
