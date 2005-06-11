# New ports collection makefile for:   p5-PodToHTML
# Date created:                27 February 2004
# Whom:                        hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	PodToHTML
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Generating HTML from several files containg POD documentation

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/HTML/FormatPS.pm:${PORTSDIR}/textproc/p5-HTML-Format
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		podtohtml.1
MAN3=		Pod::HTML_Elements.3

.include <bsd.port.mk>
