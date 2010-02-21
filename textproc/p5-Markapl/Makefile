# New ports collection makefile for:	textproc/p5-Markapl
# Date created:				15 February 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Markapl
PORTVERSION=	0.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../../authors/id/G/GU/GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Markup as Perl

BUILD_DEPENDS=	p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-HTML-Lint>=0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-B-Hooks-EndOfScope>=0.05:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-String-BufferStack>=1.15:${PORTSDIR}/textproc/p5-String-BufferStack \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Markapl.3 \
	Markapl::Helpers.3 \
	Markapl::Tags.3

.include <bsd.port.mk>
