# New ports collection makefile for:	overnet 'core' command line client
# Date created:				Wed Dec 31 22:43:16 CET 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	overnet
PORTVERSION=	1.0.1
CATEGORIES=	net linux
MASTER_SITES=	http://www.zen18864.zen.co.uk/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-core
DISTNAME=	${PORTNAME}clc-${PORTVERSION}_${ARCH}_compat
EXTRACT_SUFX=	.tgz

MAINTAINER=	arundel@h3c.de
COMMENT=	Overnet 'core' command line client

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BINARY_NAME_OLD?=	${PORTNAME}clc
TARGET_DIR=	${PORTNAME}

DOC_FILES=	ChangeLog LISEZMOI README changelog.Debian.gz

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/usr/bin/${BINARY_NAME_OLD}

do-install:
	${INSTALL} -d ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/${BINARY_NAME_OLD} ${PREFIX}/sbin/${BINARY_NAME}
	${INSTALL} -d ${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/usr/share/${PORTNAME}clc/contact.dat ${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}/contact.dat

post-install:
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}${PKGNAMESUFFIX}
.for f in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/usr/share/doc/${PORTNAME}clc/${f} ${DOCSDIR}${PKGNAMESUFFIX}
.endfor
.endif

.include <bsd.port.mk>
