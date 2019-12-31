# $FreeBSD$

PORTNAME=	cddlib
PORTVERSION=	0.94j
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	C implementation of the Double Description Method of Motzkin et al

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake libtool:build localbase:ldflags
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	cddlib

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	MANUAL EXAMPLES
OPTIONS_SUB=	yes
MANUAL_DESC=	User manual (many dependencies, including texlive)
MANUAL_BUILD_DEPENDS=	latex:print/tex-formats \
			dvips:print/tex-dvipsk

HEADERSDIR=	${PREFIX}/include/cdd

pre-build-MANUAL-off:
	${REINPLACE_CMD} 's,doc lib-src,lib-src,' ${WRKSRC}/Makefile.am

do-install:
	${MKDIR} ${STAGEDIR}${HEADERSDIR}
	cd ${WRKSRC}/src/.libs && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib-src/.libs && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib '-name *\.so*'
	cd ${WRKSRC}/lib-src/.libs && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib '-name *\.a'
	cd ${WRKSRC}/lib-src && ${COPYTREE_SHARE} . ${STAGEDIR}${HEADERSDIR} '-name *\.h'

post-install-MANUAL-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/cddlibman.dvi ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/cddlibman.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/cddlibman.ps ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "examples*" ${STAGEDIR}${EXAMPLESDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
