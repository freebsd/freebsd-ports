# New ports collection makefile for:	p5-Mojolicious-Plugin-Mongodb
# Date created:		2011-04-01
# Whom:			Henk van Oers <hvo.pm@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	Mojolicious-Plugin-Mongodb
PORTVERSION=	1.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use MongoDB in Mojolicious

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mojolicious>=0:${PORTSDIR}/www/p5-Mojolicious \
		p5-MongoDB>=0:${PORTSDIR}/databases/p5-MongoDB \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mojolicious::Plugin::Mongodb.3

.include <bsd.port.mk>
