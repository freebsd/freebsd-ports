# New ports collection makefile for:	www/p5-Catalyst-Plugin-FormBuilder
# Date created:				14 Sep 2006
# Whom:					Fernan Aguero
#
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-FormBuilder
PORTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NW/NWIGER
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	FormBuilder for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/CGI/FormBuilder.pm:${PORTSDIR}/www/p5-CGI-FormBuilder
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::FormBuilder.3

.include <bsd.port.mk>
