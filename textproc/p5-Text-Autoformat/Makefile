# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-Autoformat
PORTVERSION=	1.669.003
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/Text/DCONWAY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(...)$/\1/}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Automatic and manual text wrapping and reformating formatting

BUILD_DEPENDS=	p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-Text-Reform>=1.11:${PORTSDIR}/textproc/p5-Text-Reform
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Text::Autoformat.3

.include <bsd.port.mk>
