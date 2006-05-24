# New ports collection makefile for:	textproc/p5-Data-Report
# Date created:				24 May 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Report
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::Report - Framework for flexible reporting

COMMON_DEPENDS=	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Text-CSV_XS>0:${PORTSDIR}/textproc/p5-Text-CSV_XS
BUILD_DEPENDS=	p5-Module-Build>=0.28:${PORTSDIR}/devel/p5-Module-Build \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Data::Report.3 Data::Report::API.3 Data::Report::Base.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
