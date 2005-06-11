# New ports collection makefile for:	p5-HTML-Embperl
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-Embperl
PORTVERSION=	1.3.6
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	A module to allow embedded perl in HTML documents

.if !defined(WITHOUT_APACHE)
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
#		${SITE_PERL}/Apache/SessionX.pm:${PORTSDIR}/www/p5-Apache-SessionX
.endif

PERL_CONFIGURE=	yes

.if !defined(WITHOUT_APACHE)
CONFIGURE_ENV=	EPHTTPD="${LOCALBASE}/sbin/httpd" EPMODDIR="${LOCALBASE}/libexec/apache"
CONFIGURE_ARGS=	${LOCALBASE}/include/apache
.else
CONFIGURE_ENV=	NOAPACHE=true
.endif

INSTALL_TARGET=	pure_install

MAN3=		HTML::Embperl.3 HTML::Embperl::Faq.3 HTML::Embperl::Changes.3 \
		HTML::Embperl::FeaturesD.3 HTML::Embperl::TipsAndTricks.3 \
		HTML::Embperl::Intro.3 HTML::Embperl::Session.3 HTML::Embperl::Mail.3 \
		HTML::Embperl::INSTALL.3 HTML::Embperl::NEWS.3 HTML::EmbperlObject.3 \
		HTML::Embperl::IntroD.3 HTML::EmbperlD.3 HTML::Embperl::Features.3 \
		HTML::Embperl::IntroEmbperlObject.3 HTML::Embperl::CVS.3

MAN1=		embpexec.pl.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BROKEN=		Incorrect pkg-plist
.endif

.include <bsd.port.post.mk>
