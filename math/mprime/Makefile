# New ports collection makefile for:	mprime aka prime95
# Date created:				Tue Apr 29 03:11:28 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mprime
PORTVERSION=	0.0.${SOURCE_VERSION}
PORTREVISION=	1
CATEGORIES=	math benchmarks
MASTER_SITES=	ftp://mersenne.org/gimps/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	lioux/:local
DISTFILES=	source${PORTVERSION:S/^0.0.//:R}.zip \
		prime95-text-${TEXT_DATE}-${SOURCE_VERSION}.tar.bz2:local
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	mersenne.org distributed Great Internet Mersenne Prime Search

ONLY_FOR_ARCHS=	i386
USE_REINPLACE=	yes
USE_ZIP=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/linux
MAKEFILE=	makebsd
ALL_TARGET=	clean mprime

# source code version
SOURCE_VERSION=	22.12
# document date version
TEXT_DATE=	2003042900

post-extract:
	@cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -qq \
		${DISTDIR}/${DIST_SUBDIR}/source${PORTVERSION:S/^0.0.//:R}.zip
	@cd ${WRKDIR} && ${TAR} -xjf \
		${DISTDIR}/${DIST_SUBDIR}/prime95-text-${TEXT_DATE}-${SOURCE_VERSION}.tar.bz2

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|||' \
		-e 's|^(CC).*$$|\1=${CC}|' \
		-e 's|^(CFLAGS)[[:space:]]*=|\1+=|' \
		-e 's|^(CFLAGS.*)-m486|\1|' \
		-e 's|^(CFLAGS.*)-O2|\1|' \
		${WRKSRC}/makebsd
# prepare wrapper
	@${SED} \
		-e 's|%%PREFIX%%|${PREFIX}|' ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mprime ${PREFIX}/bin/mprime-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/mprime
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}${PKGNAMESUFFIX}
.endif

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.mk>
