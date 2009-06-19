# New ports collection makefile for:	p5-POE-Component-Generic
# Date created:		2006-08-30
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Generic
PORTVERSION=	0.12.01
DISTVERSION=	${PORTVERSION:C/\.(..)$/\1/}
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Provides non-blocking access to a blocking object

RUN_DEPENDS=	p5-POE>=0.31:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/${PERL_ARCH}/Net/SSH2.pm:${PORTSDIR}/net/p5-Net-SSH2

PERL_CONFIGURE=	5.7.2+

MAN3=		POE::Component::Generic.3 \
		POE::Component::Generic::Child.3 \
		POE::Component::Generic::Net::SSH2.3 \
		POE::Component::Generic::Object.3

.include <bsd.port.mk>
