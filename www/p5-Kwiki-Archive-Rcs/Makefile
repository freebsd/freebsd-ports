# New ports collection makefile for:	p5-Kwiki-Archive-Rcs
# Date created:				Jul 24 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Archive-Rcs
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Kwiki Page Archival Using RCS

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Archive::Rcs.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
