# New ports collection makefile for:	OpenSSL
# Version required:	0.9.4
# Date created:		Sun Jan  3 19:36:27 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	openssl-0.9.4
CATEGORIES=	security devel
MASTER_SITES=	http://www.openssl.org/source/ \
		ftp://ftp.openssl.org/source/ \
		ftp://ftp.sunet.se/pub/security/tools/net/openssl/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/

MAINTAINER=	dirk@FreeBSD.org

RESTRICTED=	"Cryptography"
USE_PERL5=	yes
ALL_TARGET=	freebsd-shared all
SHLIBVER=	1
MAKE_ENV+=	SHLIBVER=${SHLIBVER}

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO} ""
	@${ECHO} "You must set variable USA_RESIDENT to YES, if you are USA resident"
	@${ECHO} "or to NO, if you aren't USA resident to build this package."
	@${ECHO} "You must also have installed rsaref port if you are USA resident."
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES && !defined(I_HAVE_AN_RSA_LICENSE)
LIB_DEPENDS=	rsaref.2:${PORTSDIR}/security/rsaref
RSAREF=		rsaref
.endif
.endif

do-configure:
	@cd ${WRKSRC} \
	&& ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" PERL="${PERL}" \
	   ./config --prefix=${PREFIX} --openssldir=${PREFIX}/openssl \
	   ${RSAREF} -L${PREFIX}/lib

post-install:
.for i in libcrypto libssl
	@${INSTALL_DATA} ${WRKSRC}/$i.so.${SHLIBVER} ${PREFIX}/lib
	@${LN} -s $i.so.${SHLIBVER} ${PREFIX}/lib/$i.so
.endfor
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/openssl
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/openssl
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#g' ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
