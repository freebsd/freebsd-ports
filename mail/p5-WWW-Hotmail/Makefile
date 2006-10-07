# New ports collection makefile for:	p5-WWW-Hotmail
# Date created:		2006-07-20
# Whom:			Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Hotmail
PORTVERSION=	0.10
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@f2o.org
COMMENT=	This module simplifies access to hotmail

BUILD_DEPENDS=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/Mail/Audit.pm:${PORTSDIR}/mail/p5-Mail-Audit
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Hotmail.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
