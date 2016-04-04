# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	zxid
PORTVERSION=	1.42
CATEGORIES=	security www
MASTER_SITES=	http://zxid.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source IdM for the Masses - SAML SSO

LICENSE=	E2ETA
LICENSE_NAME=	End2End Trust Architecture (e2eta) Software Copying
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	# none

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake localbase tar:tgz
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

CFLAGS+=	-D_LSEEK_DECLARED -fPIC

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
	@${REINPLACE_CMD} -e \ 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/zxidconf.c ${WRKSRC}/zxididp.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${ZXID_BINS} \
		${STAGEDIR}${PREFIX}/bin)

	@${MKDIR} ${STAGEDIR}${PREFIX}/include/zx
	${LN} -sf ../zxid/zx.h ${STAGEDIR}${PREFIX}/include/zx/zx.h
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/zxid
	${INSTALL_DATA} ${WRKSRC}/*.h ${WRKSRC}/c/*.h \
		${STAGEDIR}${PREFIX}/include/zxid

	${INSTALL_DATA} ${WRKSRC}/libzxid.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libzxid.so.0.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libzxid.so.0.0 ${STAGEDIR}${PREFIX}/lib/libzxid.so
	${LN} -sf libzxid.so.0.0 ${STAGEDIR}${PREFIX}/lib/libzxid.so.0

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pd ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
