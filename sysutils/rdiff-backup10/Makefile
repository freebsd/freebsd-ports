# New ports collection makefile for:	rdiff-backup
# Date created:		Wed Jun 11 19:53:46 CEST 2003
# Whom:			Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	rdiff-backup
PORTVERSION=	1.0.5
PORTREVISION=	1
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

CONFLICTS=	rdiff-backup-1.2* rdiff-backup-devel-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		rdiff-backup.1

DOCFILES=	CHANGELOG README COPYING FAQ.html

post-install:
	${INSTALL_MAN} ${WRKSRC}/rdiff-backup.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
