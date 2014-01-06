# Created by: Cory R King <coryking@mozimedia.com>
# $FreeBSD$

PORTNAME=	URI-ToDisk
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	An object for mapping a URI to an on-disk storage directory

BUILD_DEPENDS=	p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Params-Util>=0.31:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Params-Util>=0.31:${PORTSDIR}/devel/p5-Params-Util

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
