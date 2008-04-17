# New ports collection makefile for:   p5-URI-ToDisk
# Date created:		08 March 2008
# Whom:			Cory R King <coryking@mozimedia.com>
#
# $FreeBSD$
#

PORTNAME=	URI-ToDisk
PORTVERSION=	1.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	An object for mapping a URI to an on-disk storage directory

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Params-Util>=0.31:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Params-Util>=0.31:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes

MAN3=		URI::ToDisk.3

.include <bsd.port.mk>
