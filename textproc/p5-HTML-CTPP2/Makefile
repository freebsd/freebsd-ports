# Created by: Andrei V. Shetuhin <reki@reki.ru>
# $FreeBSD$

PORTNAME=	HTML-CTPP2
PORTVERSION=	2.6.7
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN \
		http://ctpp.havoc.ru/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	reki@reki.ru
COMMENT=	Perl interface module to CTPP2 library

BUILD_DEPENDS=	ctpp2>=2.5.1:${PORTSDIR}/textproc/ctpp2
LIB_DEPENDS=	libctpp2.so:${PORTSDIR}/textproc/ctpp2

USES=		perl5
USE_PERL5=	configure

# The port actually requires ${CXX} when ${CC} is defined
CC=		${CXX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
