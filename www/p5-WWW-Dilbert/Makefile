# New ports collection makefile for:	p5-WWW-Dilbert
# Date created:				Aug 14 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	WWW-Dilbert
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dilbert of the day comic strip archive and retieval module

BUILD_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Dilbert.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601  # p5-WWW-Mechanize-1.10 requires perl 5.6.x or later.
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 or lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
