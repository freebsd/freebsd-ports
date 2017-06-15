# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apg
PORTVERSION=	2.3.0b
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Automated password generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DOCS=		APG_TIPS pronun.txt rfc0972.txt rfc1750.txt

OPTIONS_DEFINE=	CRACKLIB DOCS
CRACKLIB_DESC=	CrackLib support for password quality
CRACKLIB_LIB_DEPENDS=	libcrack.so:security/cracklib
CRACKLIB_MAKE_ARGS=	-DWITH_CRACKLIB

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgbfm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apgd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/man/apg.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgbfm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/apgd.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
