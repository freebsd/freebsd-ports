# New ports collection makefile for:	OpenSSL
# Version required:	0.9.2b
# Date created:		Sun Jan  3 19:36:27 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.ORG>
#
# $Id: Makefile,v 1.29 1999/04/13 22:37:02 dirk Exp $
#

DISTNAME=	openssl-0.9.2b
CATEGORIES=	devel security
MASTER_SITES=	http://www.openssl.org/source/ \
		ftp://ftp.openssl.org/source/ \
		ftp://ftp.sunet.se/pub/security/tools/net/openssl/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	openssl-0.9.2b-rsaoaep.patch

MAINTAINER=	dirk@FreeBSD.ORG

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"Cryptography"
USE_PERL5=	yes
MAKE_ENV=	PERL="${PERL}"

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO} ""
	@${ECHO} "You must set variable USA_RESIDENT to YES, if you are USA resident"
	@${ECHO} "or to NO, if you aren't USA resident to build this package."
	@${ECHO} "You must also have installed RSAREF if you are USA resident."
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES && !defined(I_HAVE_AN_RSA_LICENSE)
LIB_DEPENDS=	rsaref.2:${PORTSDIR}/security/rsaref

post-configure:
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/Makefile.patch
.endif
.endif

do-configure:
	@cd ${WRKSRC} \
	&& ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" PERL="${PERL}" ./config \
	&& ${PERL} util/ssldir.pl ${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/openssl
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/openssl
.endif

.include <bsd.port.mk>
