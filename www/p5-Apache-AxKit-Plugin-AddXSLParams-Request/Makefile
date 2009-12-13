# New ports collection makefile for:	p5-Apache-AxKit-Plugin-AddXSLParams-Request
# Date created:     1.8.2003
# Whom:	            Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=			Apache-AxKit-Plugin-AddXSLParams-Request
PORTVERSION=		1.02
CATEGORIES=			www perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/K/KH/KHAMPTON
PKGNAMEPREFIX=		p5-

MAINTAINER=			perl@FreeBSD.org
COMMENT=			Provides a way to pass info from the Apache::Request to XSLT params

RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Apache/libapreq.pm:${PORTSDIR}/www/p5-libapreq
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit
BUILD_DEPENDS=		${RUN_DEPENDS}

PERL_CONFIGURE=		yes

MAN3=				Apache::AxKit::Plugin::AddXSLParams::Request.3

.include <bsd.port.mk>
