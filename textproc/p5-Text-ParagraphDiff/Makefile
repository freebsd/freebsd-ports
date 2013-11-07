# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Text-ParagraphDiff
PORTVERSION=	2.70
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual difference for paragraphed text

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

WRKSRC=		${WRKDIR}/${PORTNAME}

SCRIPTS=	tdiff
EXAMPLES=	diff.html new.txt old.txt
EXAMPLESDIR=	${PREFIX}/share/examples/p5-Text-ParagraphDiff

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/bin && \
	${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
