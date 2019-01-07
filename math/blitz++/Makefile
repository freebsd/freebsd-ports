# Created by: ijliao
# $FreeBSD$

PORTNAME=	blitz++
PORTVERSION=	1.0.1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for scientific computing

LICENSE=	GPLv3 BSD3CLAUSE
LICENSE_COMB=	multi

BROKEN_FreeBSD_12=	fails to compile: ../blitz/blitz.h:58:12: 'iostream.h' file not found
BROKEN_FreeBSD_13=	fails to compile: ../blitz/blitz.h:58:12: 'iostream.h' file not found

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix python:2.7
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared CXX_OPTIMIZE_FLAGS="${CFLAGS}"
MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	blitzpp
GH_PROJECT=	blitz

PORTDOCS=	AUTHORS ChangeLog* LEGAL README NEWS \
		README.binutils TODO doc/*.txt

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
DOCS_INFO=	blitz
DOCS_USES=	makeinfo

ALL_TARGET=	all
DOCS_ALL_TARGET=	info

INSTALL_TARGET=	install-strip
DOCS_INSTALL_TARGET=	install-info

post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$${CXX}|g ; \
		 s|"-ftemplate-depth-30|"\$${CXXFLAGS} -ftemplate-depth-30|g ; \
		 s|-O3|-O2|g ; s|-funroll-loops||g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,python,${PYTHON_CMD},' ${WRKSRC}/blitz/generate/Makefile.in

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc/blitz-0.10

.include <bsd.port.mk>
