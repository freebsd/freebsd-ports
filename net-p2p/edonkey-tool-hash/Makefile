# New ports collection makefile for:	edonkey hash tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.2
CATEGORIES=	misc
MASTER_SITES=	http://users.aber.ac.uk/tpm01/ed2k_tools/
PKGNAMESUFFIX=	-tool-hash
DISTNAME=	ed2k_hash-${PORTVERSION:S/^0.//}

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=	${WRKDIR}/ed2k_hash

# I could have written a Makefile but I would rather
# not waste inodes
do-build:
	cd ${WRKSRC} && ${CC} -D__linux ${CFLAGS} ${LDFLAGS} -lmd \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib -lgnugetopt \
		ed2k_hash.c -o ${PORTNAME}${PKGNAMESUFFIX}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} \
		${PREFIX}/bin

.include <bsd.port.mk>
