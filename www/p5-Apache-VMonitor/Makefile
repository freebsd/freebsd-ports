# New ports collection makefile for:	Apache-VMonitor
# Date Created:				08 Oct 2003
# Whom:					Trevor S. Cornpropst <tcornpropst@cox.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-VMonitor
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	tcornpropst@cox.net
COMMENT=	Stas Bekman's Visual System and Apache Server Monitor

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GTop.pm:${PORTSDIR}/devel/p5-GTop \
		${SITE_PERL}/${PERL_ARCH}/Apache/Scoreboard.pm:${PORTSDIR}/www/p5-Apache-Scoreboard \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.if defined(WITH_MODPERL2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Apache::VMonitor.3

.include <bsd.port.mk>
