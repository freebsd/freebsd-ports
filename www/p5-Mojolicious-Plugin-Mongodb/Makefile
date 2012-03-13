# New ports collection makefile for:	p5-Mojolicious-Plugin-Mongodb
# Date created:		2011-04-01
# Whom:			Henk van Oers <hvo.pm@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	Mojolicious-Plugin-Mongodb
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use MongoDB in Mojolicious

RUN_DEPENDS=	p5-Mojolicious>=1:${PORTSDIR}/www/p5-Mojolicious \
		p5-MongoDB>=0:${PORTSDIR}/databases/p5-MongoDB

PERL_CONFIGURE=	yes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

MAN3=		Mojolicious::Plugin::Mongodb.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
