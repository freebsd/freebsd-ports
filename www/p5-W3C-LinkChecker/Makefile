# New ports collection makefile for:	www/p5-W3C-LinkChecker
# Date created:				25 November 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	W3C-LinkChecker
PORTVERSION=	4.6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SC/SCOP
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Checks the validity of links in an HTML or XHTML document

BUILD_DEPENDS=	${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=		checklink.1
MANCOMPRESSED=	no

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
