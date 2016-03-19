# Created by: trevor
# $FreeBSD$

PORTNAME=	outguess
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://www.outguess.org/ \
		http://www.internet2.edu/~shalunov/mirror/ \
		http://cimarron.river.com/mirrors/www.outguess.org/ \
		http://munitions.vipul.net/software/steganography/ \
		http://the25200-1.gw.connect.com.au/security/steganography/ \
		PACKETSTORM/crypt/stego

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steganographic tool

LICENSE=	BSD4CLAUSE

CONFLICTS_INSTALL=	csound-*

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/outguess

PORTDOCS=	ChangeLog README STIRMARK-README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/outguess ${STAGEDIR}${PREFIX}/bin
	${LN} -sf outguess ${STAGEDIR}${PREFIX}/bin/extract
	${INSTALL_MAN} ${WRKSRC}/outguess.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
