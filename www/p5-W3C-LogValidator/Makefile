# Created by: toni.viemero@iki.fi
# $FreeBSD$

PORTNAME=	W3C-LogValidator
PORTVERSION=	1.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Comprehensive validation tool for webmasters and web developers

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-Mail-Sendmail>=0:mail/p5-Mail-Sendmail \
		p5-WebService-Validator-CSS-W3C>=0:www/p5-webservice-validator-css-w3c \
		p5-WebService-Validator-HTML-W3C>=0:www/p5-webservice-validator-html-w3c \
		${LOCALBASE}/bin/checklink:www/p5-W3C-LinkChecker
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/samples/NewModule.pm \
		${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/samples/NewOutputModule.pm \
		${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/samples/logprocess.conf \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
