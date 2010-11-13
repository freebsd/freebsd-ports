# New ports collection makefile for:	p5-Net-WhitePages
# Date created:				16 Oct 2010
# Whom:	      				Zane C. Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-WhitePages
PORTVERSION=	1.04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides access to the XML API for WhitePages.com

RUN_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate

PERL_CONFIGURE=	yes

MAN3=		Net::WhitePages.3

.include <bsd.port.mk>
