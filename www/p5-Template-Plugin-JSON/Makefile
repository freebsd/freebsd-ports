# New ports collection makefile for:	p5-Template-Plugin-JSON
# Date created:		Dec 26, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-JSON
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adds a .json vmethod for all TT values

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mouse>0:${PORTSDIR}/devel/p5-Mouse \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-JSON>=2.12:${PORTSDIR}/converters/p5-JSON

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::JSON.3

.include <bsd.port.mk>
