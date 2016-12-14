# Created by: David Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nacl
PORTVERSION=	20110221
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://hyperelliptic.org/nacl/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	High speed cryptography library

LICENSE=	PD

USES=		tar:bzip2
ALL_TARGET=	do
USE_BINUTILS=	yes
MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	i386 amd64

HOSTNAME_CMD?=	/bin/hostname -s
MYARCH=		${ARCH:S/i386/x86/}

post-patch:
	@${REINPLACE_CMD} -e "s|$$| -fPIC|" ${WRKSRC}/okcompilers/c
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" ${WRKSRC}/okcompilers/c
	@${REINPLACE_CMD} -e "s|g++|${CXX}|" ${WRKSRC}/okcompilers/cpp

pre-build:
	${RM} -r ${WRKSRC}/crypto_onetimeauth/poly1305/amd64

do-build:
	cd ${WRKSRC} && ./do

.include <bsd.port.pre.mk>

post-build:
	${AR} -r ${WRKSRC}/build/`${HOSTNAME_CMD}`/lib/${MYARCH}/libnacl.a \
		${WRKSRC}/build/`${HOSTNAME_CMD}`/lib/${MYARCH}/randombytes.o

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/bin/nacl-sha256 \
		${STAGEDIR}${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/bin/nacl-sha512 \
		${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD}`/lib/${MYARCH}/* \
		${STAGEDIR}${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD}`/include/${MYARCH}/* \
		${STAGEDIR}${PREFIX}/include

.include <bsd.port.post.mk>
