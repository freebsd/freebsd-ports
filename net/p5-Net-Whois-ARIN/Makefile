# New ports collection makefile for:	p5-Net-Whois-ARIN
# Date created:				03 Jan 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-ARIN
PORTVERSION=	0.11
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	ARIN whois client

MAN3=	Net::Whois::ARIN.3 \
	Net::Whois::ARIN::AS.3 \
	Net::Whois::ARIN::Contact.3 \
	Net::Whois::ARIN::Customer.3 \
	Net::Whois::ARIN::Network.3 \
	Net::Whois::ARIN::Organization.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-UNIVERSAL-isa>=0:${PORTSDIR}/devel/p5-UNIVERSAL-isa \
		p5-UNIVERSAL-can>=0:${PORTSDIR}/devel/p5-UNIVERSAL-can
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
