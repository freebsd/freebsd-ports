# New ports collection makefile for:	p5-Text-ParagraphDiff
# Date created:				Nov 3 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

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
MAN3=		Text::ParagraphDiff.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/bin && \
	${INSTALL_SCRIPT} ${SCRIPTS} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
