# New ports collection makefile for:	www/p5-Template-Plugin-Subst
# Date created:				27 January 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Subst
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	TT plugin for s/// functionality in templates

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Template::Plugin::Subst.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or newer. Please install lang/perl5 or lang/perl5.6 and try again
.endif
.include <bsd.port.post.mk>
