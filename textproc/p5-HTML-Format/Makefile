# New ports collection makefile for:	p5-HTML-Format
# Date created:				25 April 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-Format
PORTVERSION=	2.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A module to format HTML to text or PS

BUILD_DEPENDS=	${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Font/AFM.pm:${PORTSDIR}/x11-fonts/p5-Font-AFM
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install
MAN3=		HTML::Formatter.3 HTML::FormatPS.3 HTML::FormatRTF.3 HTML::FormatText.3

.include <bsd.port.mk>
