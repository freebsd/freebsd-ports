# New ports collection makefile for:	XML::Sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Sablotron
PORTVERSION=	0.51
CATEGORIES=	textproc perl5
MASTER_SITES=	http://download.gingerall.cz/sablot/
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	sablot.51:${PORTSDIR}/textproc/sablotron

PERL_CONFIGURE=	yes

MAN3=		XML::Sablotron.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
