# New ports collection makefile for:   cryptopp
# Date created:        18 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		cryptopp
PORTVERSION=		5.1
PORTREVISION=		2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://www.eskimo.com/~weidai/ \
			http://gd.tuwien.ac.at/privacy/crypto/libs/cryptlib/ \
			http://www.mirrors.wiretapped.net/security/cryptography/libraries/cryptolib/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		crypto${PORTVERSION:S/.//g}
EXTRACT_SUFX=		.zip

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A free C++ class library of Cryptographic Primitives

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
USE_GMAKE=		yes
MAKEFILE=		GNUmakefile

HEADERFILES=		3way.h adler32.h aes.h algebra.h algparam.h arc4.h \
			argnames.h asn.h base64.h basecode.h bench.h \
			blowfish.h blumshub.h cast.h cbcmac.h channels.h \
			config.h crc.h cryptlib.h default.h des.h dh.h dh2.h \
			diamond.h dmac.h dsa.h ec2n.h eccrypto.h ecp.h \
			elgamal.h eprecomp.h esign.h factory.h files.h \
			filters.h fips140.h fltrimpl.h gf256.h gf2_32.h gf2n.h \
			gfpcrypt.h gost.h gzip.h haval.h hex.h hmac.h \
			hrtimer.h ida.h idea.h integer.h iterhash.h lubyrack.h \
			luc.h mars.h md2.h md4.h md5.h md5mac.h mdc.h misc.h \
			modarith.h modes.h modexppc.h mqueue.h mqv.h \
			nbtheory.h network.h nr.h oaep.h oids.h osrng.h \
			panama.h pch.h pkcspad.h polynomi.h pssr.h pubkey.h \
			pwdbased.h queue.h rabin.h randpool.h rc2.h rc5.h \
			rc6.h rijndael.h ripemd.h rng.h rsa.h rw.h safer.h \
			seal.h secblock.h seckey.h serpent.h sha.h shark.h \
			simple.h skipjack.h smartptr.h socketft.h square.h \
			strciphr.h tea.h tiger.h trdlocal.h trunhash.h \
			twofish.h validate.h wait.h wake.h winpipes.h words.h \
			xormac.h xtr.h xtrcrypt.h zdeflate.h zinflate.h zlib.h

pre-install:
	${STRIP_CMD} ${WRKSRC}/cryptest
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/cryptopp
.for H in ${HEADERFILES}
	${INSTALL_DATA} ${WRKSRC}/$H ${PREFIX}/include/cryptopp
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cryptopp
	${CP} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/cryptopp/README
	${CP} ${WRKSRC}/License.txt ${PREFIX}/share/doc/cryptopp/License
.endif

.include <bsd.port.mk>
