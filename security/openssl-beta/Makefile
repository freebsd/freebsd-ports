# New ports collection makefile for:	OpenSSL
# Version required:	0.9.1c
# Date created:		Sun Jan  3 19:36:27 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.ORG>
#
# $Id: Makefile,v 1.24 1999/01/09 12:55:48 dirk Exp $
#

DISTNAME=		openssl-0.9.1c
CATEGORIES=		devel security
MASTER_SITES=		http://www.openssl.org/source/ \
			ftp://ftp.sunet.se/pub/security/tools/net/openssl/ \
			ftp://ftp.cert.dfn.de/pub/tools/net/openssl/

MAINTAINER=		dirk@FreeBSD.ORG

RESTRICTED=		"Cryptography"
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/FreeBSD.sh
CONFIGURE_ENV=		PREFIX=${PREFIX}

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO} ""
	@${ECHO} "You must set variable USA_RESIDENT to YES, if you are USA resident"
	@${ECHO} "or to NO, if you aren\'t USA resident to build this package."
	@${ECHO} "You must also have installed RSAREF if you are USA resident."
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES && !defined(I_HAVE_AN_RSA_LICENSE)
LIB_DEPENDS=		rsaref.2:${PORTSDIR}/security/rsaref

post-configure:
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/Makefile.patch
.endif
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/apps/ssleay.cnf ${PREFIX}/etc/ssleay.cnf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/openssl
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/openssl
.endif

.include <bsd.port.mk>
