# New ports collection makefile for:	p5-Net-Address-Ethernet
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Address-Ethernet
PORTVERSION=	1.114
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Find hardware ethernet address

RUN_DEPENDS=	${SITE_PERL}/Env/Path.pm:${PORTSDIR}/devel/p5-Env-Path \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common

PERL_CONFIGURE=	yes

MAN3=		Net::Address::Ethernet.3

.include <bsd.port.mk>
