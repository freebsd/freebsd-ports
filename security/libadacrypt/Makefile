# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libadacrypt
PORTVERSION=	20151019
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Crypto library for Ada with a nice API

LICENSE=	GMGPL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ada gmake
USE_GITHUB=	yes
GH_ACCOUNT=	cforler
GH_PROJECT=	Ada-Crypto-Library
GH_TAGNAME=	abc534f

post-patch:
	@${REINPLACE_CMD} -e 's|libadacrypt-|adacrypt-|' \
		-e 's|-j4|-j${MAKE_JOBS_NUMBER}|' \
		${WRKSRC}/libadacrypt.gpr

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/adacrypt \
		${STAGEDIR}${PREFIX}/include/adacrypt
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/adacrypt
	${INSTALL_DATA} ${WRKSRC}/lib/* \
		${STAGEDIR}${PREFIX}/lib/adacrypt
	${INSTALL_DATA} ${FILESDIR}/adacrypt.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
