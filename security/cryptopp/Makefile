# New ports collection makefile for:   cryptopp
# Date created:        18 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		cryptopp
PORTVERSION=		4.1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://www.eskimo.com/~weidai/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		crypto${PORTVERSION:S/.//g}

MAINTAINER=		greid@ukug.uk.freebsd.org

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
USE_GMAKE=		yes
MAKEFILE=		GNUmakefile

HEADERFILES=		3way.h adler32.h aes.h algebra.h arc4.h asn.h base64.h \
			bench.h blowfish.h blumgold.h blumshub.h cast.h cbc.h \
			cbcmac.h channels.h config.h crc.h cryptlib.h des.h \
			default.h dh.h dh2.h diamond.h dmac.h dsa.h ec2n.h \
			eccrypto.h ecp.h elgamal.h eprecomp.h files.h gf256.h \
			filters.h gf2_32.h gf2n.h gost.h gzip.h haval.h hex.h \
			hmac.h hrtimer.h ida.h idea.h integer.h iterhash.h \
			lubyrack.h luc.h mars.h md2.h md5.h md5mac.h mdc.h \
			misc.h modarith.h modes.h modexppc.h mqueue.h mqv.h \
			nbtheory.h network.h nr.h oaep.h oids.h osrng.h \
			panama.h pch.h pkcspad.h polynomi.h pssr.h pubkey.h \
			queue.h rabin.h randpool.h rc2.h rc5.h rc6.h \
			rijndael.h ripemd.h rng.h rsa.h rw.h safer.h \
			sapphire.h seal.h secshare.h serpent.h sha.h shark.h \
			skipjack.h smartptr.h socketft.h square.h tea.h \
			tiger.h twofish.h validate.h wake.h winpipes.h words.h \
			xormac.h xtr.h xtrcrypt.h zdeflate.h zinflate.h zlib.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/cryptopp
.for H in ${HEADERFILES}
	${INSTALL_DATA} ${WRKSRC}/$H ${PREFIX}/include/cryptopp
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cryptopp
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/cryptopp/README
.endif

.include <bsd.port.mk>
