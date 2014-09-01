# Created by: adamw
# $FreeBSD$

PORTNAME=	Crypt-Tea_JS
PORTVERSION=	2.23
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Tiny Encryption Algorithm in Perl and Javascript

CONFLICTS=	p5-Crypt-T_e_a-[0-9]*

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES
PORTEXAMPLES=	tea_demo.cgi
PORTDATA=	Tea_JS.js

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Tea_JS.js ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
