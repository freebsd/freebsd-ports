# $FreeBSD$

PORTNAME=	signify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Create and verify cryptographic signatures

# outils includes signify from OpenBSD's base system which is under an
# ISC license.  The parts of liboutils that signify uses are licensed
# under ISCL/BSD3/BSD4.
LICENSE=	BSD3CLAUSE BSD4CLAUSE ISCL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	leahneukirchen
GH_PROJECT=	outils

ALL_TARGET=	src/usr.bin/signify/signify

PLIST_FILES=	bin/signify \
		share/man/man1/signify.1.gz

post-patch:
# The sys/* overrides are not needed on FreeBSD
	@${RM} ${WRKSRC}/src/liboutils/include/sys/*
# Replace /etc/signify paths in man page and signify's safe path to
# point to /usr/local/etc/signify
	@${REINPLACE_CMD} 's|/etc/signify|${ETCDIR}|g' \
		${WRKSRC}/src/usr.bin/signify/signify.c \
		${WRKSRC}/src/usr.bin/signify/signify.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/usr.bin/signify/signify \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/usr.bin/signify/signify.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/openbsd-*.pub \
		${STAGEDIR}${ETCDIR}
	cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${ETCDIR_REL} -name 'openbsd-*.pub' -type f >> ${TMPPLIST}

.include <bsd.port.mk>
