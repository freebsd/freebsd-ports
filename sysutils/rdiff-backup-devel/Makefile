# New ports collection makefile for:	rdiff-backup-devel
# Date created:				10 Nov 2005
# Whom:					Vasil Dimov <vd@datamax.bg>
#
# $FreeBSD$
#

PORTNAME=	rdiff-backup
PORTVERSION=	1.3.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH:S/$/:savannah/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:savannah \
		vd/${PORTNAME}${PKGNAMESUFFIX}/:local
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:savannah,local

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Local/remote mirroring+incremental backup

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync

CONFLICTS=	rdiff-backup-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		rdiff-backup.1 rdiff-backup-statistics.1

DOCFILES=	CHANGELOG README COPYING FAQ.html

post-install:
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${man} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
