# New ports collection makefile for:	pdumpfs-clean
# Date created:		29 May 2004
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pdumpfs-clean
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://tach.arege.net/software/pdumpfs-clean/
DISTFILES=	${PROG}
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A utility to clean up old backup files of a pdumpfs archive

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
