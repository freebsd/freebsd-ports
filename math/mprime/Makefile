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

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	mersenne.org distributed Great Internet Mersenne Prime Search

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message wrapper.sh

# source code version
SOURCE_VERSION=	24.14

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mprime ${PREFIX}/bin/mprime-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/mprime
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}${PKGNAMESUFFIX}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
