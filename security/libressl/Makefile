# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD: head/security/libressl/Makefile 395668 2015-08-31 12:25:43Z brnrd $

PORTNAME=	libressl
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	openbsd

OPTIONS_DEFINE= MAN3
OPTIONS_DEFAULT=MAN3
MAN3_DESC=      Install API manpages (section 3)

CONFLICTS?=	openssl-[0-9]* \

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-silent-rules
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

#.if ${ARCH} == "amd64"
#CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
#.endif

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

OPTIONS_DEFINE= MAN3
OPTIONS_DEFAULT=MAN3
MAN3_DESC=      Install API manpages (section 3)

post-install-MAN3-off:
	${RM} -rf ${STAGEDIR}/${PREFIX}/man/man3
	${REINPLACE_CMD} -e '/^man\/man3/d' ${TMPPLIST}

.include <bsd.port.post.mk>
