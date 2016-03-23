# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD: head/security/libressl/Makefile 405314 2016-01-05 19:47:13Z brnrd $

PORTNAME=	libressl
PORTVERSION=	2.2.6
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	openbsd

OPTIONS_DEFINE=	CERTBUNDLE MAN3
OPTIONS_DEFAULT=	CERTBUNDLE MAN3
CERTBUNDLE_DESC=	Install LibreSSL's cert bundle ${PREFIX}/etc/ssl/cert.pem
MAN3_DESC=	Install API manpages (section 3)

CONFLICTS?=	libressl-devel-[0-9]* \
		openssl-[0-9]* \
		openssl-devel-[0-9]*

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

post-install-MAN3-off:
	${RM} -rf ${STAGEDIR}/${PREFIX}/man/man3
	${REINPLACE_CMD} -e '/^man\/man3/d' ${TMPPLIST}

post-install:
	${RM} -rf ${STAGEDIR}/${PREFIX}/etc/ssl/cert.pem

.include <bsd.port.post.mk>
