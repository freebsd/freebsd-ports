# New ports collection makefile for:	stunnel
# Version required:	2.1
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $Id: Makefile,v 1.3 1999/03/29 14:54:37 dirk Exp $
#

DISTNAME=	stunnel-2.1
CATEGORIES=	security
MASTER_SITES=	http://mike.daewoo.com.pl/computer/stunnel/ \
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
WRKSRC=		${WRKDIR}/stunnel
MAN8=		stunnel.8

.include <bsd.port.mk>
