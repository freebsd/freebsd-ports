# New ports collection makefile for:	textproc/p5-Text-Graphics
# Date created:				30 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Graphics
PORTVERSION=	1.0001
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A text graphics rendering toolkit

BUILD_DEPENDS=	${SITE_PERL}/Text/Wrapper.pm:${PORTSDIR}/textproc/p5-Text-Wrapper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Graphics.3

post-patch:
	@${RM} ${WRKSRC}/lib/Text/Graphics.pm.orig

.include <bsd.port.mk>
