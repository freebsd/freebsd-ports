# New ports collection makefile for:	p5-Catalyst-View-JSON
# Date created:		May 10, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-JSON
PORTVERSION=	0.14
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Catalyst View handler that returns stash data in JSON format

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel

OPTIONS=	JSONSYCK "Use JSON::Syck rather than JSON::Converter" off

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::JSON.3 Catalyst::View::JSON.3

.include <bsd.port.pre.mk>

.if defined(WITH_JSONSYCK)
RUN_DEPENDS+=	p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
.else
RUN_DEPENDS+=	p5-JSON>=1.00:${PORTSDIR}/converters/p5-JSON
.endif

.include <bsd.port.post.mk>
