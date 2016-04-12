# Created by: Andrei V. Shetuhin <reki@reki.ru>
# $FreeBSD$

PORTNAME=	HTML-CTPP2
PORTVERSION=	2.6.7
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN \
		http://ctpp.havoc.ru/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	reki@reki.ru
COMMENT=	Perl interface module to CTPP2 library

BUILD_DEPENDS=	ctpp2>=2.5.1:textproc/ctpp2
LIB_DEPENDS=	libctpp2.so:textproc/ctpp2

USES=		perl5
USE_PERL5=	configure

# The port actually requires ${CXX} when ${CC} is defined
CC=		${CXX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; \
		/^my $$CXX/s|g++|${CXX}|; /^my $$CC/s|gcc|${CC}|' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200
BROKEN=		Fails to build with Perl >= 5.22
.endif

.include <bsd.port.post.mk>
