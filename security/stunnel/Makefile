# New ports collection makefile for:	stunnel
# Version required:	3.3
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

DISTNAME=	stunnel-3.3
CATEGORIES=	security
MASTER_SITES=	http://mike.daewoo.com.pl/computer/stunnel/ \
		http://opensores.thebunker.net/pub/mirrors/stunnel/ \
		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
		ftp://ftp.uni-freiburg.de/pub/net/stunnel/ \
		ftp://ftp.all.de/pub2/unix/security/stunnel/

MAINTAINER=	martti.kuparinen@ericsson.com

BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/libssl.a:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/libcrypto.a:${PORTSDIR}/security/openssl
RUN_DEPENDS=	openssl:${PORTSDIR}/security/openssl

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
LIB_DEPENDS=	rsaref.2:${PORTSDIR}/security/rsaref
MAKE_ENV+=	EXTRA_SSL_LIBS="-lRSAglue -lrsaref"
.endif

GNU_CONFIGURE=	yes
MAN8=		stunnel.8

cert:
	@(cd ${WRKSRC}; make cert)

post-build:
	@${ECHO} ""
	@${ECHO} "********************************************************************"
	@${ECHO} "To create and install a real certificate, execute \"make cert\" before"
	@${ECHO} "\"make install\"."
	@${ECHO} ""
	@${ECHO} "You can also create a real certificate later by executing"
	@${ECHO} "      # make cert"
	@${ECHO} "      # cp work/stunnel/stunnel.pem ${PREFIX}/certs/"
	@${ECHO} "********************************************************************"
	@${ECHO} ""

post-install:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "Please check out the FAQ at http://mike.daewoo.com.pl/computer/stunnel/FAQ"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""

.include <bsd.port.mk>
