# New ports collection makefile for:	pdumpfs-rsync
# Date created:		29 May 2004
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pdumpfs-rsync
PORTVERSION=	0.8.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://tach.arege.net/software/pdumpfs-rsync/
DISTFILES=	${PROG}
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A utility to back up remote files with pdumpfs and rsync

RUN_DEPENDS=	${LOCALBASE}/sbin/pdumpfs:${PORTSDIR}/sysutils/pdumpfs \
		rsync:${PORTSDIR}/net/rsync

USE_RUBY=	yes
RUBY_SHEBANG_FILES=	${PROG}

PROG=		${PORTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	sbin/${PROG}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PROG} ${WRKDIR}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PROG} ${PREFIX}/sbin/

.include <bsd.port.mk>
