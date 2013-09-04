# New ports collection makefile for:	p5-Mail-CheckUser
# Date created:				2 January 2004
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	Mail-CheckUser
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bra@fsn.hu
COMMENT=	Perl module to check email addresses for validity

BUILD_DEPENDS=  p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		cufilter.1
MAN3=           Mail::CheckUser.3

.include <bsd.port.mk>
