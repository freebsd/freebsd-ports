# New ports collection makefile for:	p5-CatalystX-InjectComponent
# Date created:		2011-05-08
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CatalystX-InjectComponent
PORTVERSION=	0.024
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Inject components into your Catalyst application

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.8:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.8:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

PERL_CONFIGURE=	yes

MAN3=		CatalystX::InjectComponent.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
