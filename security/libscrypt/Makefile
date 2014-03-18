# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	libscrypt
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	horia@racoviceanu.com
COMMENT=	C library for the scrypt key derivation function

LICENSE=	BSD2CLAUSE

USES=		compiler
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	technion
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	35b6894

MAKE_ARGS+=	CC=${CC} LIBDIR=${PREFIX}/lib

PLIST_FILES=	include/libscrypt.h \
		lib/libscrypt.so \
		lib/libscrypt.so.0

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=STACKPROTECTOR

OPTIONS_SINGLE=	BUFFER_OVERFLOW_PROTECTION
OPTIONS_SINGLE_BUFFER_OVERFLOW_PROTECTION=	STACKPROTECTOR STACKPROTECTORALL

STACKPROTECTOR_DESC=	Protect functions with vulnerable objects
STACKPROTECTORALL_DESC=	Protect all functions

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|?=-|+=-|; s|-O2 ||' ${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MSTACKPROTECTORALL}
	@${REINPLACE_CMD} -e 's|stack-protector|&-all|' ${WRKSRC}/Makefile
.endif

.if ${ARCH} == i386 && ${COMPILER_TYPE} == gcc && ${OSVERSION} < 1000036
	@${REINPLACE_CMD} -e 's|-lscrypt|& -lssp_nonshared|; \
		s|\.version|&,-lssp_nonshared|' ${WRKSRC}/Makefile
.endif

	@${REINPLACE_CMD} -e \
		's|strcpy(mcf2, mcf);|strlcpy(mcf2, mcf, SCRYPT_MCF_LEN);|' \
			${WRKSRC}/main.c

regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
