# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	rdiff-backup
PORTVERSION=	1.2.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH:S/$/:savannah/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:savannah \
		vd/${PORTNAME}${PKGNAMESUFFIX}/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:savannah,local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Local/remote mirroring+incremental backup

LICENSE=	GPLv2

LIB_DEPENDS=	librsync.so:${PORTSDIR}/net/librsync

CONFLICTS=	rdiff-backup-devel-[0-9]* rdiff-backup-1.0*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1S=		rdiff-backup.1 rdiff-backup-statistics.1
DOCS=		CHANGELOG README COPYING FAQ.html

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${MAN1S:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
