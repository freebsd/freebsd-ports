# New ports collection makefile for:	rsaref
# Version required:	2.0
# Date created:		2 Feb 1997
# Whom:			ache
#
# $FreeBSD$
#

DISTNAME=	rsaref20.1996
PKGNAME=	rsaref-2.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.deva.net/pub/sources/crypto/ \
		ftp://ftp.kddlabs.co.jp/.7/inet/caida/bmwt/ \
		ftp://ftp.zedz.net/pub/crypto/crypto/LIBS/rsa/ \
		ftp://ftp.hacktic.nl/pub/crypto/crypto/LIBS/rsa/ \
		ftp://ftp.demon.net/pub/mirrors/crypto/replay/crypto/LIBS/rsa/ \
		ftp://ftp.jyu.fi/.3/ftp.zedz.net/pub/replay/crypto/LIBS/rsa/ \
		ftp://ftp.funet.fi/pub/mirrors/utopia.hacktic.nl/crypto/LIBS/rsa/ \
		ftp://ftp.fu-berlin.de/unix/security/replay-mirror/crypto/LIBS/rsa/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/source
RESTRICTED=	"Crypto"

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	cd ${WRKSRC} && \
		${CP} des.h _des.h && \
		${CP} md2.h _md2.h && \
		${CP} md5.h _md5.h

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsaref
.for file in info.txt rsaref.txt
	${INSTALL_DATA} ${WRKSRC}/../doc/${file} ${PREFIX}/share/doc/rsaref
.endfor
.endif

.include <bsd.port.mk>
