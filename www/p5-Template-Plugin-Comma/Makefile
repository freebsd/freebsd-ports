# New ports collection makefile for:	p5-Template-Plugin-Comma
# Date created:		19 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Comma
PORTVERSION=	0.04
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	TT Plugin to commify numbers

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Template::Plugin::Comma.3

.include <bsd.port.mk>
