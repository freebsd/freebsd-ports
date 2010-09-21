# New ports collection makefile for:	v6eval
# Date created:		Mon Jan  6 23:07:28 GMT 2003
# Whom:			TANAKA Takashi <tanaka@tahi.org>
#
# $FreeBSD$
#

PORTNAME=	v6eval
PORTVERSION=	3.0.1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tahi.org/release/v6eval/

MAINTAINER=	Yukiyo.Akisada@jp.yokogawa.com
COMMENT=		IPv6 Conformance Test Platform

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect

USE_PERL5=	yes
USE_OPENSSL=	yes
NO_MANCOMPRESS=	yes
MAN1PREFIX=	${PREFIX}/v6eval
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		pktctl.1.gz pktsend.1.gz
MAN3=		V6evalRemote.3 V6evalTool.3
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
