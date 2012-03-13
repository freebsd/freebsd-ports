# New ports collection makefile for:	p5-Marpa-HTML
# Date created:		2011-10-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Marpa-HTML
PORTVERSION=	0.112
CATEGORIES=	textproc lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}000

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-level HTML Parser

BUILD_DEPENDS=	p5-HTML-Parser>=3.64:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Marpa-PP>=0.012:${PORTSDIR}/lang/p5-Marpa-PP \
		p5-Marpa-XS>=0.026:${PORTSDIR}/lang/p5-Marpa-XS
RUN_DEPENDS=	p5-HTML-Parser>=3.64:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Marpa-PP>=0.012:${PORTSDIR}/lang/p5-Marpa-PP \
		p5-Marpa-XS>=0.026:${PORTSDIR}/lang/p5-Marpa-XS

PERL_CONFIGURE=	5.10.0+

MAN1=		html_fmt.1 \
		html_score.1
MAN3=		Marpa::HTML.3 \
		Marpa::HTML::Support.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Data-Dumper>=2.125:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS+=	p5-Data-Dumper>=2.125:${PORTSDIR}/devel/p5-Data-Dumper
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib/Marpa/Support.pod|lib/Marpa/HTML/Support.pod|' ${WRKSRC}/Build.PL

.include <bsd.port.post.mk>
