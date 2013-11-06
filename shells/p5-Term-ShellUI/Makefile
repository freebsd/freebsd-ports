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
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	cd ${WRKSRC}/examples/ && ${INSTALL_SCRIPT} \
		fileman-example synopsis synopsis-big tui-sample ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
