# Created by: siasia
# $FreeBSD$

PORTNAME=	tralics
PORTVERSION=	2.15.4
DISTVERSIONPREFIX=	src-
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp-sop.inria.fr/marelle/tralics/src/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	LaTeX to XML translator

BROKEN=		fetch fails, checksum mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	CeCILLv21
LICENSE_NAME=	Ce(A)C(nrs)I(NRIA)L(ogiciel)L(ibre) version 2.1
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/Licence_CeCILL_V2-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAKE_ARGS=	CC="${CXX}" CXX="${CXX}" CPPFLAGS="${CXXFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
