# New ports collection makefile for:	p5-WWW-Mixi
# Date created:		2005-08-06
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mixi
PORTVERSION=	0.44
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Perl module of Automated interface to the Mixi

BUILD_DEPENDS=	${SITE_PERL}/LWP/RobotUA.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Mixi.3 WWW::Mixi::Cookbook.3 WWW::Mixi::Mixi.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.x or later. Install lang/perl5 then try again
.elif ${PERL_LEVEL} > 500800
BUILD_DEPENDS+=	${SITE_PERL}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode
.endif

.include <bsd.port.post.mk>
