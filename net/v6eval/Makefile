# New ports collection makefile for:	v6eval
# Date created:		Mon Jan  6 23:07:28 GMT 2003
# Whom:			TANAKA Takashi <tanaka@tahi.org>
#
# $FreeBSD$
#

PORTNAME=	v6eval
PORTVERSION=	3.0.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tahi.org/release/v6eval/

MAINTAINER=	Yukiyo.Akisada@jp.yokogawa.com
COMMENT=		IPv6 Conformance Test Platform

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5=	yes
USE_OPENSSL=	yes
NOMANCOMPRESS=	yes
MAN1PREFIX=	${PREFIX}/v6eval
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		pktctl.1.gz pktsend.1.gz
MAN3=		V6evalRemote.3 V6evalTool.3

.include <bsd.port.pre.mk>

post-install:
	@${SED} -e 's#@LOCALBASE@#${LOCALBASE}#' ${PKGMESSAGE}

.include <bsd.port.post.mk>
