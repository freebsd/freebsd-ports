# ex:ts=8
# Ports collection makefile for:	ccrypt
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ccrypt
PORTVERSION=	1.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://quasar.mathstat.uottawa.ca/~selinger/ccrypt/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jim@corebsd.or.id
COMMENT=	A command-line utility for encrypting and decrypting files and streams

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes

MAN1=	ccrypt.1
MLINKS=	ccrypt.1 ccencrypt.1 \
	ccrypt.1 ccdecrypt.1 \
	ccrypt.1 ccat.1

post-patch:
	@${REINPLACE_CMD} -e 's|gtar|tar|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README doc/ccrypt.html doc/cypfaq01.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
