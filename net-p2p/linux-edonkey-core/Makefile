# New ports collection makefile for:	eDonkey2000 'core' command line client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.2000.15.16.58.0.2
CATEGORIES=	net linux
MASTER_SITES=	http://users.aber.ac.uk/tpm01/
PKGNAMESUFFIX=	-core
DISTNAME=	donkey_s_58test-2
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

BINARY_NAME=	donkey

post-extract:
	@${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKSRC}/${BINARY_NAME}

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin/${BINARY_NAME}-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${BINARY_NAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}${PKGNAMESUFFIX}
.endif
	@${SED} s!/usr/local/share/doc/edonkey-core!${DOCSDIR}${PKGNAMESUFFIX}! ${PKGMESSAGE}

.include <bsd.port.mk>
