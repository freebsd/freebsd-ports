# New ports collection Makefile for:	pamsfs
# Date created:				2005-09-13
# Whom:					David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	pamsfs
PORTVERSION=	0.1b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.codecobra.com/pamsfs/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A PAM module to mount SFS home directories

BUILD_DEPENDS=	sfskey:${PORTSDIR}/security/sfs

ALL_TARGET=	pam-sfs
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	lib/pam_sfs.so
PORTDOCS=	README

pre-build:
	@${REINPLACE_CMD} -e "s|/usr/local/sfs-0.7.2|${PREFIX}|g" ${WRKSRC}/pam_sfs.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pam_sfs.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
