# New ports collection makefile for:	p5-Template-Plugin-JSON
# Date created:		Dec 26, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-JSON
PORTVERSION=	0.02
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adds a .json vmethod for all TT values

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Template-Plugin-VMethods>0:${PORTSDIR}/www/p5-Template-Plugin-VMethods

OPTIONS=	JSONSYCK "Use JSON::Syck rather than JSON::Converter" off

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::JSON.3

.include <bsd.port.pre.mk>

.if defined(WITH_JSONSYCK)
RUN_DEPENDS+=	p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
.else
RUN_DEPENDS+=	p5-JSON>=1.00:${PORTSDIR}/converters/p5-JSON
.endif

.include <bsd.port.post.mk>
