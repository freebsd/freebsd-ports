# New ports collection makefile for:   p5-Apache-ParseFormData
# Date created:                13-Jul-2004
# Whom:                        Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-ParseFormData
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	nistor@snickers.org
COMMENT=	Module allows you to easily decode/parse form and query data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

BROKEN=		Broken due the new mod_perl2 API

MAN3=		Apache::ParseFormData.3

.include <bsd.port.pre.mk>

# mod_perl 2 requires it
.if ${PERL_LEVEL} < 500800
IGNORE=         requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
