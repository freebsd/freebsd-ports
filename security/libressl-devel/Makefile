# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libressl
PORTVERSION=	2.5.0
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	openbsd

OPTIONS_DEFINE=	MAN3 NC
OPTIONS_DEFAULT=	MAN3 NC
MAN3_DESC=	Install API manpages (section 3)
NC_DESC=	Install TLS-enabled netcat

CONFLICTS_INSTALL=	libressl-[0-9]* \
			openssl-[0-9]* \
			openssl-devel-[0-9]*

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
CFLAGS+=	-fpic -DPIC

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-install:
	${RM} -r ${STAGEDIR}/${PREFIX}/etc/ssl/cert.pem

post-install-NC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/apps/nc/.libs/nc ${STAGEDIR}/${PREFIX}/bin/nc
	${INSTALL_MAN} ${WRKSRC}/apps/nc/nc.1 ${STAGEDIR}/${PREFIX}/man/man1/nc.1

post-install-MAN3-off:
	${RM} -r ${STAGEDIR}/${PREFIX}/man/man3
	${REINPLACE_CMD} -e '/^man\/man3/d' ${TMPPLIST}

.include <bsd.port.mk>
