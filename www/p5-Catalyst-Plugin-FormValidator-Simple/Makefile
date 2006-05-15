# New ports collection makefile for:	www/p5-Catalyst-Plugin-FormValidator-Simple
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-FormValidator-Simple
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/L/LY/LYOKATO
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Validator for Catalyst with FormValidator::Simple

BUILD_DEPENDS=	p5-Catalyst>=5.30:${PORTSDIR}/www/p5-Catalyst \
		p5-Catalyst-Plugin-FormValidator>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-FormValidator \
		p5-FormValidator-Simple>=0.13:${PORTSDIR}/textproc/p5-FormValidator-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::FormValidator::Simple.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
