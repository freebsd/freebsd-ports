# New ports collection makefile for:	textproc/p5-Text-Autoformat
# Date created:				28 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Autoformat
PORTVERSION=	1.669.001
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/Text/DCONWAY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(...)$/\1/}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Automatic and manual text wrapping and reformating formatting

BUILD_DEPENDS=	p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-Text-Reform>=1.11:${PORTSDIR}/textproc/p5-Text-Reform
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Autoformat.3

.include <bsd.port.mk>
