# New ports collection makefile for:	rsaref
# Date created:		2 Feb 1997
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	rsaref
PORTVERSION=	2.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.deva.net/pub/sources/crypto/ \
		ftp://ftp.kddlabs.co.jp/.7/inet/caida/bmwt/ \
		ftp://ftp.zedz.net/pub/crypto/crypto/LIBS/rsa/ \
		ftp://ftp.hacktic.nl/pub/crypto/crypto/LIBS/rsa/ \
		ftp://ftp.demon.net/pub/mirrors/crypto/replay/crypto/LIBS/rsa/ \
		ftp://ftp.funet.fi/pub/mirrors/utopia.hacktic.nl/crypto/LIBS/rsa/ \
		ftp://ftp.fu-berlin.de/unix/security/replay-mirror/crypto/LIBS/rsa/
DISTNAME=	rsaref20.1996
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/source
RESTRICTED=	"Contains cryptography"

INSTALLS_SHLIB=	yes

pre-extract:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	/usr/bin/more -e ${FILESDIR}/LICENSE.english
	/usr/bin/dialog --yesno "Do you accept the terms of the RSAREF license agreement and wish to proceed with the build?" 8 40 || ${FALSE}
.endif

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	cd ${WRKSRC} && \
		${CP} des.h _des.h && \
		${CP} md2.h _md2.h && \
		${CP} md5.h _md5.h

do-install:
.for file in rsa.h _des.h _md2.h _md5.h rsaref.h global.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
	${INSTALL_DATA} ${WRKSRC}/librsaref.a ${WRKSRC}/librsaref.so.2 \
		${PREFIX}/lib
	${LN} -sf librsaref.so.2 ${PREFIX}/lib/librsaref.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsaref
.for file in info.txt rsaref.txt
	${INSTALL_DATA} ${WRKSRC}/../doc/${file} ${PREFIX}/share/doc/rsaref
.endfor
.endif

.include <bsd.port.mk>
