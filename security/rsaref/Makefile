# New ports collection makefile for: rsaref
# Version required:     2.0
#
# Date created:         2 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1998/09/16 14:08:47 smace Exp $
#

DISTNAME=       rsaref20.1996
PKGNAME=        rsaref-2.0
CATEGORIES=     security
MASTER_SITES=   ftp://utopia.hacktic.nl/pub/replay/pub/crypto/LIBS/rsa/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	ache@FreeBSD.ORG

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
