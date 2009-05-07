# New ports collection makefile for:	rdiff-backup
# Date created:		Wed Jun 11 19:53:46 CEST 2003
# Whom:			Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	rdiff-backup
PORTVERSION=	1.2.8
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH:S/$/:savannah/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:savannah \
		vd/${PORTNAME}${PKGNAMESUFFIX}/:local
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:savannah,local

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Local/remote mirroring+incremental backup

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync

CONFLICTS=	rdiff-backup-devel-[0-9]* rdiff-backup-1.0*

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
