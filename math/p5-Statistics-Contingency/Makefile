# New ports collection makefile for:	math/p5-Statistics-Contingency
# Date created:				Tue Dec 30 19:57:00 CST 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Statistics-Contingency
PORTVERSION=	0.06
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Statistics
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Calculate precision, recall, F1, accuracy, etc

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Statistics::Contingency.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port will require perl 5.6.x or later in the future. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
