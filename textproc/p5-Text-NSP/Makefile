# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Text-NSP
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Ngram Statistics Package

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

DOCS=	CHANGES README doc/FAQ.pod doc/NSP-Class-diagram.pdf \
	doc/NSP-Class-diagram.png doc/README.pod doc/TODO.pod \
	doc/USAGE.pod doc/cicling2003.pdf doc/cicling2003.ps
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
