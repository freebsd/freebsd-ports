# Created by: Mitsuru Y <mitsuruy@reallyenglish.com>
# $FreeBSD$

PORTNAME=	ElasticSearch-SearchBuilder
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT=	A Perlish compact query language for ElasticSearch

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	YES

MAN3=		ElasticSearch::SearchBuilder.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
