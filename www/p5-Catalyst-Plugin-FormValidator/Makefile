# New ports collection makefile for:	www/p5-Catalyst-Plugin-FormValidator
# Date created:				07 May 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-FormValidator
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	FormValidator for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::FormValidator.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
