# New ports collection makefile for: rsaref
# Version required:     2.0
#
# Date created:         2 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1997/02/02 21:25:02 ache Exp $
#

PKGNAME=        rsaref-2.0
DISTNAME=       rsaref20.1996
CATEGORIES=     security
MASTER_SITES=   ftp://utopia.hacktic.nl/pub/replay/pub/crypto/LIBS/rsa/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/source
RESTRICTED=     "Crypto"

pre-configure:
	cp ${FILESDIR}/Makefile ${WRKSRC}
	cd ${WRKSRC} && \
		cp des.h _des.h && \
		cp md2.h _md2.h && \
		cp md5.h _md5.h

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} rsa.h _des.h _md2.h _md5.h rsaref.h global.h \
			${PREFIX}/include
	cd ${WRKSRC} && \
		${INSTALL_DATA} librsaref.a librsaref.so.2.0 \
			${PREFIX}/lib
	${LDCONFIG} -m ${PREFIX}/lib
	install -d -m 555 ${PREFIX}/share/doc/rsaref
	cd ${WRKDIR}/doc && \
		${INSTALL_DATA} info.txt rsaref.txt \
			${PREFIX}/share/doc/rsaref

.include <bsd.port.mk>
