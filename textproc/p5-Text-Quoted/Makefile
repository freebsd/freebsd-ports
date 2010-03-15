# New ports collection makefile for:	p5-Text-Quoted
# Date created:				Mon April 14th, 2003
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Quoted
PORTVERSION=	2.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Text::Quoted - Extract the structure of a quoted mail message

BUILD_DEPENDS=	${SITE_PERL}/Text/Autoformat.pm:${PORTSDIR}/textproc/p5-Text-Autoformat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Quoted.3

.include <bsd.port.mk>
