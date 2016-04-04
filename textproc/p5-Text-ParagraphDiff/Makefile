# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Text-ParagraphDiff
PORTVERSION=	2.70
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Visual difference for paragraphed text

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-HTML-Parser>=0:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/tdiff
USE_PERL5=	configure
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

SCRIPTS=	tdiff
EXAMPLES=	diff.html new.txt old.txt
EXAMPLESDIR=	${PREFIX}/share/examples/p5-Text-ParagraphDiff

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/bin && \
	${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
