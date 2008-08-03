# New ports collection makefile for:   p5-HTML-Location
# Date created:                                08 September 2007
# Whom:                                        coryking
#
# $FreeBSD$
#

PORTNAME=	HTML-Location
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Working with disk to URI file mappings (deprecated: see URI::ToDisk)

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-PathTools>=3.25:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-PathTools>=3.25:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		HTML::Location.3

.include <bsd.port.mk>
