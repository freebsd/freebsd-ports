# New ports collection makefile for:	p5-W3C-LogValidator
# Date created:			Jun 24, 2004
# Whom:				toni.viemero@iki.fi
#
# $FreeBSD$
#

PORTNAME=	W3C-LogValidator
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	A comprehensive validation tool for webmasters and web developers

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/WebService/Validator/CSS/W3C.pm:${PORTSDIR}/www/p5-webservice-validator-css-w3c \
		${SITE_PERL}/WebService/Validator/HTML/W3C.pm:${PORTSDIR}/www/p5-webservice-validator-html-w3c \
		${LOCALBASE}/bin/checklink:${PORTSDIR}/www/p5-W3C-LinkChecker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.2+	# inherited from www/p5-webservice-validator-css-w3c

MAN3=	W3C::LogValidator.3 \
	W3C::LogValidator::Basic.3 \
	W3C::LogValidator::CSSValidator.3 \
	W3C::LogValidator::Config.3 \
	W3C::LogValidator::HTMLValidator.3 \
	W3C::LogValidator::Output::HTML.3 \
	W3C::LogValidator::Output::Mail.3 \
	W3C::LogValidator::Output::Raw.3 \
	W3C::LogValidator::SurveyEngine.3

post-install:
.ifndef (NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/samples/NewModule.pm ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/samples/NewOutputModule.pm ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/samples/logprocess.conf ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
