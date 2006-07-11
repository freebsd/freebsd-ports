# New ports collection makefile for:	p5-WWW-OpenSearch
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-OpenSearch
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Search A9 OpenSearch compatible engines

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/Data/Page.pm:${PORTSDIR}/databases/p5-Data-Page \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/RSS/LibXML.pm:${PORTSDIR}/textproc/p5-XML-RSS-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::OpenSearch.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703	# inherited from textproc/p5-XML-RSS-LibXML
IGNORE=	requires perl 5.7.3 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
