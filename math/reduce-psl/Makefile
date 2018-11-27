# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	reduce
PORTVERSION=	20181123
CATEGORIES=	math lang
MASTER_SITES=	SF/reduce-algebra/${SFSUBDIR}/
PKGNAMESUFFIX=	-psl
DISTNAME=	Reduce-svn4829-src

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	REDUCE Portable Standard Lisp general-purpose algebra system

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		autoreconf:build libtool gmake ncurses

SFSUBDIR=	snapshot_2018-11-23

TARGET_SDIR=	${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=	--build=${TARGET_SDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}
CPPFLAGS+=	-I${NCURSESINC}

# Avoid GNU_CONFIGURE as it breaks staging
HAS_CONFIGURE=	yes
ALL_TARGET=

MAKE_JOBS_UNSAFE=	yes

PLIST=		${.CURDIR}/pkg-plist.${ARCH}

CONFIGURE_ARGS=	--with-psl

REDUCE_BINS=	${WRKSRC}/pslbuild/${TARGET_SDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/runpsl.sh ${STAGEDIR}${PREFIX}/bin/redpsl
	${INSTALL_MAN} ${FILESDIR}/redpsl.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DATADIR}/psl
	${INSTALL_PROGRAM} ${REDUCE_BINS}/psl/bpsl ${STAGEDIR}${DATADIR}/psl/
	(cd ${REDUCE_BINS}/psl && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/psl "! -name bpsl")
	${MKDIR} ${STAGEDIR}${PREFIX}/red
	(cd ${REDUCE_BINS}/red && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/red)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc//util/r38.pdf	\
	    ${STAGEDIR}${DOCSDIR}/manual.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/primers/*.pdf \
	    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
