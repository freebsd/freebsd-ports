# New ports collection makefile for:	Linux eDonkey server
# Date created:				18 December 2001
# Whom:	Yen-Ming Lee <leeym@leeym.com> & Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	16.39
PORTREVISION=	1
CATEGORIES=	net-p2p linux
MASTER_SITES=	http://www.edonkey2000.com/files/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-server
DISTNAME=	dserver
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A decentralized peer-to-peer file-sharing server (eDonkey2000 server)

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
#
PKGDEINSTALL=	${PKGINSTALL}

BINARY_NAME=	dserver
RC_SAMPLE=	edonkey2000-server.sh.sample

post-extract:
	@${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKSRC}/${BINARY_NAME}

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|" ${FILESDIR}/${RC_SAMPLE} \
		> ${WRKDIR}/${RC_SAMPLE}

do-install:
# pre-install work: create user ids, ...
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${INSTALL_PROGRAM} ${WRKDIR}/${BINARY_NAME} ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/${RC_SAMPLE} ${PREFIX}/etc/rc.d
	@${INSTALL_DATA} ${FILESDIR}/donkey.ini ${PREFIX}/etc/edonkey2000

.include <bsd.port.pre.mk>

pre-install:
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

.include <bsd.port.post.mk>
