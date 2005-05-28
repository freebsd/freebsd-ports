# New ports collection makefile for:	mprime aka prime95
# Date created:				Tue Apr 29 03:11:28 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mprime
PORTVERSION=	0.0.${SOURCE_VERSION}
CATEGORIES=	math benchmarks net
MASTER_SITES=	ftp://mersenne.org/gimps/
DISTNAME=	sprime${PORTVERSION:S/^0.0.//:S/.//}-freebsd

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	mersenne.org distributed Great Internet Mersenne Prime Search

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# source code version
SOURCE_VERSION=	23.5

post-patch:
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
