# New ports collection makefile for:	edonkey server list tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	http://users.aber.ac.uk/tpm01/ed2k_tools/
PKGNAMESUFFIX=	-tool-slist
DISTNAME=	ed2k_slist-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Checks which servers are either dead or alive in server.met

WRKSRC=	${WRKDIR}/ed2k_slist
USE_REINPLACE=	yes
USE_SIZE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|||' ${WRKSRC}/*.[ch]

# I could have written a Makefile but I would rather
# not waste inodes
do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} \
		ed2k_slist.c -o ${PORTNAME}${PKGNAMESUFFIX}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} \
		${PREFIX}/bin

.include <bsd.port.mk>
