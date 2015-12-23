# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Lite
PORTVERSION=	3.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Process and decode WWW forms and cookies

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5 shebangfix
SHEBANG_FILES=	examples/*
USE_PERL5=	configure
NO_ARCH=	yes

PORTEXAMPLES=	cookies file get_post post print reference upload

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
