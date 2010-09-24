# New ports collection makefile for:	www/p5-Catalyst-Plugin-FormBuilder
# Date created:				14 Sep 2006
# Whom:					Fernan Aguero
#
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-FormBuilder
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	FormBuilder for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-CGI-FormBuilder>=3.02:${PORTSDIR}/www/p5-CGI-FormBuilder
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::FormBuilder.3

.include <bsd.port.mk>
