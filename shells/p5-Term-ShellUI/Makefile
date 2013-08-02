# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Term-ShellUI
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fully-featured shell-like command line environment

BUILD_DEPENDS=	p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu
RUN_DEPENDS=	p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu

USES=		perl5
USE_PERL5=	configure

MAN3=		Term::ShellUI.3 \
		Text::Shellwords::Cursor.3

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	cd ${WRKSRC}/examples/ && ${INSTALL_SCRIPT} \
		fileman-example synopsis synopsis-big tui-sample ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
