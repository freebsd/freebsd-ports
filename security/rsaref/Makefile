# New ports collection makefile for: rsaref
# Version required:     2.0
#
# Date created:         2 Feb 1997
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       rsaref20.1996
PKGNAME=        rsaref-2.0
CATEGORIES=     security
MASTER_SITES=   ftp://utopia.hacktic.nl/pub/replay/pub/crypto/LIBS/rsa/ \
		ftp://ftp.ntua.gr/pub/crypt/mirrors/utopia.hacktic.nl/crypto/LIBS/math/ \
		ftp://ftp.tuwien.ac.at/opsys/linux/replay.com/crypto/LIBS/math/ \
		ftp://ftp.nstu.ru/pub/sources/security/crypt/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	ache@FreeBSD.org

WRKSRC=         ${WRKDIR}/source
RESTRICTED=     "Crypto"

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	cd ${WRKSRC} && \
		${CP} des.h _des.h && \
		${CP} md2.h _md2.h && \
		${CP} md5.h _md5.h

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL} -d -m 555 ${PREFIX}/share/doc/rsaref
	cd ${WRKDIR}/doc && ${INSTALL_DATA} info.txt rsaref.txt \
		${PREFIX}/share/doc/rsaref

.include <bsd.port.mk>
