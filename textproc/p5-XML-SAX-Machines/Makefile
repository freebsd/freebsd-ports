# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAX-Machines
PORTVERSION=	0.46
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERIGRIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manage collections of SAX processors

BUILD_DEPENDS=	p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

regression-test: build
	${MAKE} -C ${WRKSRC} test

post-install:
		@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
		@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
