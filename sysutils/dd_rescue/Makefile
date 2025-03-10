PORTNAME=	dd_rescue
PORTVERSION=	1.99.14
CATEGORIES=	sysutils
MASTER_SITES=	http://www.garloff.de/kurt/linux/ddrescue/ \
		http://fossies.org/unix/privat/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	dd tool suitable for rescuing data from a medium with errors
WWW=		http://www.garloff.de/kurt/linux/ddrescue/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		Fails to link: undefined reference to find_nonzero_arm8

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		autoreconf gmake ssl tar:bzip2
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
ALL_TARGET=	default
MAKE_ARGS=	EXTRA_LDFLAGS=-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -Wno-int-conversion
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dd_rescue ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libddr_crypt.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libddr_hash.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libddr_null.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libddr_lzo.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/dd_rescue.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/ddr_crypt.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/ddr_lzo.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README.dd_rescue ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
