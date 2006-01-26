# New ports collection makefile for:	www/p5-Template-Plugin-Number-Format
# Date created:				26 January 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Number-Format
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Plugin/filter interface to Number::Format

BUILD_DEPENDS=	p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format \
		p5-Template-Toolkit>=2.07:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::Number::Format.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6 or newer. Please install lang/perl or lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
