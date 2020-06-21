# Created by: ijliao
# $FreeBSD$

PORTNAME=	blitz++
PORTVERSION=	1.0.2
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for scientific computing

LICENSE=	ART20 BSD3CLAUSE LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE_ART20=		${WRKSRC}/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYRIGHT
LICENSE_FILE_LGPL3+ =		${WRKSRC}/COPYING.LESSER

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		autoreconf compiler gmake libtool pathfix python:2.7
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	blitzpp
GH_PROJECT=	blitz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared CXX_OPTIMIZE_FLAGS="${CFLAGS}" \
		COMPILER=${COMPILER_TYPE}

BINARY_ALIAS=	python=${PYTHON_CMD}

PORTDOCS=	AUTHORS ChangeLog* LEGAL README NEWS \
		README.binutils indirect.txt \
		sinsoid.txt slice.txt \
		strideslice.txt tensor1.txt

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_INFO=		blitz
DOCS_USES=		makeinfo
DOCS_INSTALL_TARGET=	install-info

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
PLIST_SUB=	COMPILER=llvm
.elif ${COMPILER_TYPE} == gcc
PLIST_SUB=	COMPILER=gnu
.else
IGNORE=	compiler is not supported
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$${CXX}|g ; \
		 s|"-ftemplate-depth-30|"\$${CXXFLAGS} -ftemplate-depth-30|g ; \
		 s|-O3|-O2|g ; s|-funroll-loops||g' ${WRKSRC}/configure
	cd ${WRKSRC}/m4 && ${RM} libtool.m4 ltoptions.m4 ltsugar.m4 ltversion.m4 lt~obsolete.m4

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS:N*.txt} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS:M*.txt} ${STAGEDIR}${DOCSDIR}

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc/blitz-1.0.2

.include <bsd.port.post.mk>
