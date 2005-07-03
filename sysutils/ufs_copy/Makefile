# New ports collection makefile for:   ufs_copy
# Date created:        3 July 2005
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ufs_copy
PORTVERSION=	20041015
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~simokawa/ufs/
DISTNAME=	ufs-${PORTVERSION}

MAINTAINER=	nobutaka@freebsd.org
COMMENT=	Fast copy utility for UFS filesystem

WRKSRC=		${WRKDIR}/ufs
MAKE_ARGS=	BINDIR=${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		FreeBSD 4.x does not have libufs
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
