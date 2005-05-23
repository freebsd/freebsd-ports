# New ports collection makefile for:	edonkey server list tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	# http://users.aber.ac.uk/tpm01/ed2k_tools/
PKGNAMESUFFIX=	-tool-slist
DISTNAME=	ed2k_slist-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks which servers are either dead or alive in server.met

EXPIRATION_DATE=2005-09-01
DEPRECATED=	"No longer available"

WRKSRC=	${WRKDIR}/ed2k_slist
USE_REINPLACE=	yes
DOCSDIR=	${PREFIX}/${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	bin/edonkey-tool-slist
.ifndef(NOPORTDOCS)
PORTDOCS=	COPYING
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|||' ${WRKSRC}/*.[ch]

# I could have written a Makefile but I would rather
# not waste inodes
do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} \
		ed2k_slist.c -o ${PORTNAME}${PKGNAMESUFFIX}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}

.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} \
		${PREFIX}/bin

.include <bsd.port.mk>
