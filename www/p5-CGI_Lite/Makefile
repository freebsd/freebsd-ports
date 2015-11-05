# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Lite
PORTVERSION=	3.00
PORTREVISION=	1
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

DOCS=		CHANGES README TODO
EXAMPLES=	cookies get_post print upload file post reference

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_SCRIPT} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
