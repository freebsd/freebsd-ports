# New ports collection makefile for:	p5-XML-Reader
# Date created:				20 Oct, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Reader
PORTVERSION=	0.44
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reading XML and providing path information based on a pull-parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser

OPTIONS_DEFINE=	PP
PP_DESC=	Use XML::Parsepp (Perl 5.14+ required)

PERL_CONFIGURE=	yes

MAN3=		XML::Reader.3 \
		XML::Reader_de.3 \
		XML::Reader_fr.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPP}
BUILD_DEPENDS+=	p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp
RUN_DEPENDS+=	p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp
.else
BUILD_DEPENDS+=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS+=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
TEST_DEPENDS+=	p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp
.endif

.include <bsd.port.post.mk>
