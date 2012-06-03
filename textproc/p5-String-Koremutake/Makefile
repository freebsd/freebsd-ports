# New ports collection makefile for:	textproc/p5-String-Koremutake
# Date created:				27 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Koremutake
PORTVERSION=	0.30
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Convert to/from Koremutake Memorable Random Strings

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	String::Koremutake.3

.include <bsd.port.mk>
