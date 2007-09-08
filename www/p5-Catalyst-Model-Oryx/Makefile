# New ports collection makefile for:	www/p5-Catalyst-Model-Oryx
# Date created:				10 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-Oryx
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Oryx model component for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Oryx.pm:${PORTSDIR}/databases/p5-Oryx \
		${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::Model::Oryx.3 \
	Catalyst::Model::Oryx.3

.include <bsd.port.mk>
