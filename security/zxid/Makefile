# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	zxid
PORTVERSION=	1.22
CATEGORIES=	security www
MASTER_SITES=	http://zxid.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source IdM for the Masses - SAML SSO

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		gmake tar:tgz
USE_OPENSSL=	yes
USE_CSTD=	gnu89
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		LD="${CC}" LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}" OPENSSL_ROOT="${OPENSSLBASE}" \
		POSTLIBS="${LDFLAGS}" TARGET="${OPSYS:tl}" \
		V=1
ALL_TARGET=	default smime libzxid.so.0.0
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include -D_LSEEK_DECLARED -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_powerpc=	Does not build on ${ARCH}
BROKEN_sparc64=	Does not build on ${ARCH}

OPTIONS_DEFINE=	DOCS

ZXID_BINS=	smime zxcall zxcot zxdecode zxencdectest zxidhlo \
		zxidhlowsf zxidhrxmlwsc zxidhrxmlwsp zxididp zxidsimple \
		zxidwsctool zxlogview zxpasswd

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LIBS/s|-lpthread|-pthread| ; \
		 /^SHARED/s|--export-all-symbols|| ; \
		 /..error /d ; \
		 /which gcc/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/zxidconf.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${ZXID_BINS} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/zx
	${LN} -sf ../zxid/zx.h ${STAGEDIR}${PREFIX}/include/zx/zx.h
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/zxid
	(cd ${WRKSRC} && ${INSTALL_DATA} *.h c/*.h \
		${STAGEDIR}${PREFIX}/include/zxid)
	(cd ${WRKSRC} && ${INSTALL_DATA} libzxid.a \
		${STAGEDIR}${PREFIX}/lib)
	(cd ${WRKSRC} && ${INSTALL_LIB} libzxid.so.0.0 \
		${STAGEDIR}${PREFIX}/lib)
	${LN} -sf libzxid.so.0.0 ${STAGEDIR}${PREFIX}/lib/libzxid.so
	${LN} -sf libzxid.so.0.0 ${STAGEDIR}${PREFIX}/lib/libzxid.so.0
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.pd \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
