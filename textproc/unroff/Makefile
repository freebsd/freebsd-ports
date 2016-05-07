# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unroff
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://www-rn.informatik.uni-bremen.de/software/unroff/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
DIST_SUBDIR=	unroff

PATCH_SITES=	http://www-rn.informatik.uni-bremen.de/software/unroff/contrib/
PATCHFILES=	me-misc-patch.gz misc-patch-2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programmable troff translator with backend for HTML

LICENSE=	UNROFF
LICENSE_NAME=	unroff license
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libelk.so:lang/elk

BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DBSD"	\
		INCLUDE="-I${LOCALBASE}/include/elk"	\
		LIBS="-lm -lelk -L${LOCALBASE}/lib"	\
		ELKDIR="${LOCALBASE}/share/elk"		\
		DIR="${DATADIR}" ELK=""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unroff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/misc
.for i in doc/tmac.hyper misc/sample.unroff
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}/misc
.endfor
	${TAR} -C ${WRKSRC} -cf - scm | \
		${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.ms ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
