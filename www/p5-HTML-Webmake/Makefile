# New ports collection makefile for:	p5-HTML-Parser
# Date created: 			21 June 2002
# Whom:					Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-WebMake
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://webmake.sourceforge.net/released/ \
		http://webmake.taint.org/released/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple perl based website content management system

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Text-EtText>=0:${PORTSDIR}/textproc/p5-Text-EtText \
		p5-XML-Sablotron>=0:${PORTSDIR}/textproc/p5-XML-Sablotron \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		webmake.1
MAN3=		HTML::WebMake.3 HTML::WebMake::MetadataContent.3 HTML::WebMake::PerlCodeLibrary.3 \
		HTML::WebMake::Content.3 HTML::WebMake::Main.3 HTML::WebMake::Util.3

.include <bsd.port.mk>
