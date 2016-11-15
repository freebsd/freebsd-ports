# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libressl
PORTVERSION=	2.4.4
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	openbsd

OPTIONS_DEFINE=	MAN3 NC
OPTIONS_DEFAULT=	MAN3 NC
MAN3_DESC=	Install API manpages (section 3)
NC_DESC=	Install TLS-enabled netcat

CONFLICTS_INSTALL=	libressl-devel-[0-9]* \
			openssl-[0-9]* \
			openssl-devel-[0-9]*

MAN3_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-MAN3

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
CFLAGS+=	-fpic -DPIC

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-stage-NC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/apps/nc/.libs/nc ${STAGEDIR}/${PREFIX}/bin/nc
	${INSTALL_MAN} ${WRKSRC}/apps/nc/nc.1 ${STAGEDIR}/${PREFIX}/man/man1/nc.1

post-stage:
	${RM} -r ${STAGEDIR}/${PREFIX}/etc/ssl/cert.pem

.include <bsd.port.mk>
