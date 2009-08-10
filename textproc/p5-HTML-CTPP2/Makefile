# New ports collection makefile for:	p5-HTML-CTPP2
# Date Created:				20 Mar, 2008
# Whom:					Andrei V. Shetuhin <reki@reki.ru>
#
# $FreeBSD$
#

PORTNAME=	HTML-CTPP2
PORTVERSION=	2.5.9
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN \
		http://ctpp.havoc.ru/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	reki@reki.ru
COMMENT=	Perl interface module to CTPP2 library

BUILD_DEPENDS=	ctpp2>=2.5.1:${PORTSDIR}/textproc/ctpp2
LIB_DEPENDS=	ctpp2:${PORTSDIR}/textproc/ctpp2

PERL_CONFIGURE=	yes

MAN3=		HTML::CTPP2.3

# The port actually requires ${CXX} when ${CC} is defined
CC=		${CXX}

.include <bsd.port.mk>
