# New ports collection makefile for:    p5-Net-Divert
# Date created:                         January 30, 2003
# Whom:                                 Nicolas Jombart
#
# $FreeBSD$

PORTNAME=	Net-RawSock
PORTVERSION=	1.0
CATEGORIES=	net perl5
MASTER_SITES=	http://www.hsc.fr/ressources/outils/rawsock/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ecu@ipv42.net

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::RawSock.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README demo.pl
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
