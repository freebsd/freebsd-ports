# New ports collection makefile for:	p5-HTML-Parser
# Date created: 			21 June 2002
# Whom:					Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-WebMake
PORTVERSION=	2.3
CATEGORIES=	www perl5
MASTER_SITES=	http://webmake.sourceforge.net/released/ \
		http://webmake.taint.org/released/
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	A simple perl based website content management system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Text/EtText.pm:${PORTSDIR}/textproc/p5-Text-EtText \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		webmake.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::WebMake.3 HTML::WebMake::PerlCodeLibrary.3 \
		HTML::WebMake::Content.3 HTML::WebMake::Main.3

.include <bsd.port.mk>
