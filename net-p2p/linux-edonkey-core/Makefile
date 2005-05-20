# New ports collection makefile for:	eDonkey2000 'core' command line client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	net linux
MASTER_SITES=	http://www.zen18864.zen.co.uk/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-core
DISTNAME=	${PORTNAME}clc-${PORTVERSION}_${ARCH}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	eDonkey2000 'core' command line client

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=

BINARY_NAME_OLD?=	${PORTNAME}clc
BINARY_NAME=	donkey

DOC_FILES=	ChangeLog LISEZMOI README changelog.Debian.gz

pre-install:

	@${BRANDELF} -t Linux ${WRKSRC}/usr/bin/${BINARY_NAME_OLD}

do-install:
	${INSTALL} -d ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/${BINARY_NAME_OLD} ${PREFIX}/sbin/${BINARY_NAME}
	${INSTALL} -d ${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/usr/share/${PORTNAME}clc/contact.dat ${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}/contact.dat
	${INSTALL_DATA} ${WRKSRC}/usr/share/${PORTNAME}clc/server.met ${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}/server.met

post-install:
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}${PKGNAMESUFFIX}

.for file in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/usr/share/doc/${PORTNAME}clc/${file} ${DOCSDIR}${PKGNAMESUFFIX}
.endfor

	${INSTALL_MAN} ${FILESDIR}/README.FreeBSD ${DOCSDIR}${PKGNAMESUFFIX}
.endif
	@${SED} -e 's|%%DOCSDIR%%|${DOCSDIR}${PKGNAMESUFFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
