# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Syntax-Highlight-Engine-Kate
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Port of the syntax highlight engine of the Kate texteditor

TEST_DEPENDS=	p5-Test-Differences>0:${PORTSDIR}/devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
