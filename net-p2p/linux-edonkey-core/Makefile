# New ports collection makefile for:	eDonkey2000 'core' command line client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.50.1
PORTEPOCH=	1
CATEGORIES=	net linux
MASTER_SITES=	http://www.overnet.com/files/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-core
DISTNAME=	donkey${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	eDonkey2000 'core' command line client

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_SIZE=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

BINARY_NAME_OLD?=	donkey${PORTVERSION}
BINARY_NAME=	donkey

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME_OLD} ${PREFIX}/sbin/${BINARY_NAME}-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${BINARY_NAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}${PKGNAMESUFFIX}
.endif
	@${SED} s!/usr/local/share/doc/edonkey-core!${DOCSDIR}${PKGNAMESUFFIX}! ${PKGMESSAGE}

.include <bsd.port.pre.mk>

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME_OLD}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME_OLD}

.include <bsd.port.post.mk>
