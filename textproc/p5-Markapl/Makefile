# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Markapl
PORTVERSION=	0.14
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Markup as Perl

LICENSE=	MIT

BUILD_DEPENDS=	p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-HTML-Lint>=0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-B-Hooks-EndOfScope>=0.05:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-String-BufferStack>=1.15:${PORTSDIR}/textproc/p5-String-BufferStack \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Markapl.3 \
	Markapl::Helpers.3 \
	Markapl::Tags.3

.include <bsd.port.mk>
