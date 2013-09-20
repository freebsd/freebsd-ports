# Created by: hrs@FreeBSD.org
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

USES=		perl5
USE_PERL5=	configure

MAN1=		podtohtml.1
MAN3=		Pod::HTML_Elements.3 \
		Pod::Links.3

NO_STAGE=	yes
.include <bsd.port.mk>
