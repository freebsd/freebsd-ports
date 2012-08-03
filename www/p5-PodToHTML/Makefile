# New ports collection makefile for:   p5-PodToHTML
# Date created:                27 February 2004
# Whom:                        hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	PodToHTML
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Generating HTML from several files containing POD documentation

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Format>=0:${PORTSDIR}/textproc/p5-HTML-Format
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		podtohtml.1
MAN3=		Pod::HTML_Elements.3 \
		Pod::Links.3

.include <bsd.port.mk>
