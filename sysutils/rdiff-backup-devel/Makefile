# Created by: Vasil Dimov <vd@datamax.bg>
# $FreeBSD$

PORTNAME=	rdiff-backup
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH:S/$/:savannah/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:savannah \
		vd/${PORTNAME}${PKGNAMESUFFIX}/:local
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:savannah,local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Local/remote mirroring+incremental backup

LICENSE=	GPLv2

LIB_DEPENDS=	rsync:${PORTSDIR}/net/librsync

CONFLICTS=	rdiff-backup-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		rdiff-backup.1 rdiff-backup-statistics.1

PORTDOCS=	CHANGELOG README COPYING FAQ.html

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
