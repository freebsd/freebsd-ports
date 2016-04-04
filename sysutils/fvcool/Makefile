# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$

PORTNAME=	fvcool
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/fvcool/
DISTNAME=	FVCool${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VCool for FreeBSD - Cooling software for AMD Athlon/Duron CPUs

LICENSE=	BSD3CLAUSE # misses 2nd clause, but it's still not BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/CopyRight

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_RC_SUBR=	fvcool
SUB_FILES=	pkg-message
SUB_LIST=	"PORTNAME=${PORTNAME}"
ALL_TARGET=	fvcool

PORTDOCS=	ReadMe ReadMe.jp ReadMe.tech_KT133
PLIST_FILES=	sbin/fvcool

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|@CC@|& ${CFLAGS}|; \
		s|-O3||g ; s| -s | |g' ${BUILD_WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${STAGEDIR}${PREFIX}/sbin/fvcool

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
