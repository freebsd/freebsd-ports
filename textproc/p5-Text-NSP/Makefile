# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Text-NSP
PORTVERSION=	1.27
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Ngram Statistics Package

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	CHANGES README doc/FAQ.pod doc/NSP-Class-diagram.pdf \
	doc/NSP-Class-diagram.png doc/README.pod doc/TODO.pod \
	doc/USAGE.pod doc/cicling2003.pdf doc/cicling2003.ps \

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===>   Installing documentation in ${DOCSDIR}"
.endif

.include <bsd.port.mk>
