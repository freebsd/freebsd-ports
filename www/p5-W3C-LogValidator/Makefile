# New ports collection makefile for:	p5-W3C-LogValidator
# Date created:			Jun 24, 2004
# Whom:				toni.viemero@iki.fi
#
# $FreeBSD$
#

PORTNAME=	W3C-LogValidator
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	W3C
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	A comprehensive validation tool for webmasters and web developers

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	W3C::LogValidator.3 \
	W3C::LogValidator::Basic.3 \
	W3C::LogValidator::Config.3 \
	W3C::LogValidator::CSSValidator.3 \
	W3C::LogValidator::HTMLValidator.3 \
	W3C::LogValidator::SurveyEngine.3 \
	W3C::LogValidator::Output::HTML.3 \
	W3C::LogValidator::Output::Mail.3 \
	W3C::LogValidator::Output::Raw.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.if ${PERL_LEVEL} < 500600
post-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | \
		${XARGS} ${PERL5} -pi -e 's/^our ([^;=]+)/use vars qw(\1); \1/;'
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/logprocess.conf ${EXAMPLESDIR}

.include <bsd.port.post.mk>
