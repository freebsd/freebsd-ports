# New ports collection makefile for:	net/p5-Phone-Info
# Date created:				16 Oct 2010
# Whom:	      				Zane C. Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Phone-Info
PORTVERSION=	0.0.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN/../../authors/id/V/VV/VVELOX/
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides a nicer CLI interface to Net::WhitePages

RUN_DEPENDS=	${SITE_PERL}/Net/WhitePages.pm:${PORTSDIR}/net/p5-Net-WhitePages

PERL_CONFIGURE=	yes

MAN3=		Phone::Info.3

.include <bsd.port.mk>
