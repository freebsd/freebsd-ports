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
		http://www.internet2.edu/~shalunov/mirror/ \
		http://cimarron.river.com/mirrors/www.outguess.org/ \
		http://munitions.vipul.net/software/steganography/ \
		http://the25200-1.gw.connect.com.au/security/steganography/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	crypt/stego

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Steganographic tool

DOCDIR=		share/doc/outguess
DOCS=		ChangeLog README STIRMARK-README TODO

GNU_CONFIGURE=	yes
MAN1=		outguess.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/outguess

pre-install:
	${ECHO_CMD} bin/extract > ${PLIST}
	${ECHO_CMD} bin/outguess >> ${PLIST}
#	${ECHO_CMD} bin/histogram >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
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
