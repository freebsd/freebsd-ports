# New ports collection makefile for:	URI-OpenURL
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-OpenURL
PORTVERSION=	0.4.6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Parse and construct OpenURL's (NISO Z39.88-2004)

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	URI::OpenURL.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	uses the utf8 pragma and therefore requires at least Perl5.8
.endif

.include <bsd.port.post.mk>
