# New ports collection makefile for:	outguess
# Date created:        			2000-12-31
# Whom:					trevor
# based on the OpenBSD port by Dug Song <dugsong@monkey.org>
#
# $OpenBSD: Makefile,v 1.7 2000/10/22 15:43:25 espie Exp $
# $FreeBSD$
#

PORTNAME=	outguess
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://www.outguess.org/ \
		ftp://ftp.cryptoarchive.net/pub/cryptoarchive/mirrors/www-sites/www.outguess.org/ \
		http://www.physnet.uni-hamburg.de/provos/ \
		http://munitions.vipul.net/software/steganography/

MAINTAINER=	Trevor Johnson <trevor@FreeBSD.org>

DOCDIR=		share/doc/outguess
DOCS=		ChangeLog README STIRMARK-README TODO

GNU_CONFIGURE=	yes
MAN1=		outguess.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/outguess

pre-install:
	${ECHO} bin/extract > ${PLIST}
	${ECHO} bin/outguess >> ${PLIST}
#	${ECHO} bin/histogram >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/outguess ${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/histogram ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/outguess ${PREFIX}/bin/extract
	${INSTALL_MAN} ${WRKSRC}/outguess.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
