# New ports collection makefile for:	p5-Template-Multilingual
# Date created:		19 June 2005
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Multilingual
PORTVERSION=	0.09
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Multilingual templates for Template Toolkit

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

PERL_CONFIGURE=	yes

MAN3=		Template::Multilingual.3 \
		Template::Multilingual::Parser.3

.include <bsd.port.mk>
