# New ports collection makefile for:	p5-Template-Plugin-Monta
# Date created:				14 June 2005
# Whom:					TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Monta
PORTVERSION=	0.03
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Template-Toolkit plugin to Monta Method

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL}/Acme/Monta.pm:${PORTSDIR}/www/p5-Acme-Monta

PERL_CONFIGURE=	yes

MAN3=		Template::Plugin::Monta.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or greater. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
