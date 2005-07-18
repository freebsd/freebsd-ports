# New ports collection makefile for:	p5-Template-Multilingual
# Date created:		19 June 2005
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Multilingual
PORTVERSION=	0.05
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Multilingual templates for Template Toolkit

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

PERL_CONFIGURE=	yes

MAN3=		Template::Multilingual.3 \
		Template::Multilingual::Parser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=         Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
