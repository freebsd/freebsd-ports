# New ports collection makefile for:	p5-Kwiki-Archive-SVK
# Date created:		Aug 12 2004
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Archive-SVK
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki Page Archival Using SVK

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki \
		${SITE_PERL}/SVK.pm:${PORTSDIR}/devel/svk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Archive::SVK.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
