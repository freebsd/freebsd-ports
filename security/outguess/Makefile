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
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	crypt/stego

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steganographic tool

CONFLICTS_INSTALL=	csound-*
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/outguess
PORTDOCS=	ChangeLog README STIRMARK-README TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/outguess ${STAGEDIR}${PREFIX}/bin
	${LN} -sf outguess ${STAGEDIR}${PREFIX}/bin/extract
	${INSTALL_MAN} ${WRKSRC}/outguess.1 ${STAGEDIR}${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
