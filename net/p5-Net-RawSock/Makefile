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
COMMENT=	Net::RawSock provides a base function to send raw IP packets from Perl

PERL_CONFIGURE=	yes

MAN3=		Net::RawSock.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/RawSock.pm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README demo.pl
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
