# New ports collection makefile for:	p5-Text-ParagraphDiff
# Date created:				Nov 3 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Text-ParagraphDiff
PORTVERSION=	2.70
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual difference for paragraphed text

BUILD_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

SCRIPTS=	tdiff
EXAMPLES=	diff.html new.txt old.txt
EXAMPLESDIR=	${PREFIX}/share/examples/p5-Text-ParagraphDiff
MAN3=		Text::ParagraphDiff.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/bin && \
	${INSTALL_SCRIPT} ${SCRIPTS} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
