# New ports collection makefile for:	p5-Bundle-Slash
# Date created:				March 17th 2002
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Bundle-Slash
PORTVERSION=	2.52
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A bundle to install all modules used for Slash

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/CalendarMonthSimple.pm:${PORTSDIR}/www/p5-HTML-CalendarMonthSimple \
		${SITE_PERL}/Font/AFM.pm:${PORTSDIR}/x11-fonts/p5-Font-AFM \
		${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Schedule/Cron.pm:${PORTSDIR}/sysutils/p5-Schedule-Cron \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/DBIx/Password.pm:${PORTSDIR}/databases/p5-DBIx-Password
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
USE_APACHE=	13+
USE_MYSQL=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.if ${APACHE_VERSION} == 13
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/Cookie.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp1
.else
BUILD_DEPENDS+=	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp2
.endif

MAN3=		Bundle::Slash.3

.include <bsd.port.post.mk>
