# New ports collection makefile for:	AnyEvent::Twitter
# Date created:				07 Nov 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-Twitter
PORTVERSION=	0.27
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@tandon.net
COMMENT=	Implementation of the Twitter API for AnyEvent

BUILD_DEPENDS=	p5-AnyEvent>=3.5:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-HTTP>=0:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Object-Event>=1.2:${PORTSDIR}/devel/p5-Object-Event \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		AnyEvent::Twitter.3

.include <bsd.port.mk>
