PORTNAME=	reduce
PORTVERSION=	${SFSUBDIR:S/snapshot_//:S/-//g}
CATEGORIES=	math lang
MASTER_SITES=	SF/reduce-algebra/${SFSUBDIR}/
PKGNAMESUFFIX=	-psl
DISTNAME=	Reduce-svn6860-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Standard Lisp REDUCE general-purpose algebra system
WWW=		http://www.reduce-algebra.com/

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		autoreconf:build libtool gmake ncurses

SFSUBDIR=	snapshot_2024-08-12

TARGET_SDIR=	${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}${OSREL}
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
	${INSTALL_MAN} ${FILESDIR}/redpsl.1 ${STAGEDIR}${PREFIX}/share/man/man1/
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
