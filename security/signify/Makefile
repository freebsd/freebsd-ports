# $FreeBSD$

PORTNAME=	signify
PORTVERSION=	0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Create and verify cryptographic signatures

# outils includes signify from OpenBSD's base system which is under an
# ISC license.  The parts of liboutils that signify uses are licensed
# under ISCL/BSD3/BSD4.
LICENSE=	ISCL BSD4CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	chneukirchen
GH_PROJECT=	outils

ALL_TARGET=	src/usr.bin/signify/signify

post-patch:
# sys/cdefs.h and sys/limits.h override is not needed on FreeBSD
	${RM} ${WRKSRC}/src/liboutils/include/sys/cdefs.h
	${RM} ${WRKSRC}/src/liboutils/include/sys/limits.h
# Replace /etc/signify paths in man page and signify's safe path to
# point to /usr/local/etc/signify
	${REINPLACE_CMD} 's|/etc/signify/|${ETCDIR}/|g' \
		${WRKSRC}/src/usr.bin/signify/signify.c \
		${WRKSRC}/src/usr.bin/signify/signify.1
	${REINPLACE_CMD} -e 's|-lcrypto||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/usr.bin/signify/signify \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/usr.bin/signify/signify.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/openbsd-*.pub \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
