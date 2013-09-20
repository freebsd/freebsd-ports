# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ufs_copy
PORTVERSION=	20060921
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~simokawa/ufs/
DISTNAME=	ufs-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Fast copy utility for UFS filesystem

WRKSRC=		${WRKDIR}/ufs
MAKE_ARGS=	BINDIR=${PREFIX}/sbin

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
