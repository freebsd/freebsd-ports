# $FreeBSD$

PORTNAME=	Net-RawSock
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	http://www.hsc.fr/ressources/outils/rawsock/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ecu@200ok.org
COMMENT=	Net::RawSock provides a base function to send raw IP packets from Perl

BROKEN=		unfetchable

USES=		perl5
USE_PERL5=	configure patch

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README demo.pl

.include <bsd.port.options.mk>

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/RawSock.pm

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/RawSock/RawSock.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
