# New ports collection makefile for:	stunnel
# Version required:	2.1
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $Id: Makefile,v 1.1.1.1 1999/01/18 04:27:02 steve Exp $
#

DISTNAME=	stunnel-2.1
CATEGORIES=	security
MASTER_SITES=	http://mike.daewoo.com.pl/computer/stunnel/ \
		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
		ftp://ftp.uni-freiburg.de/pub/net/stunnel/ \
		ftp://ftp.all.de/pub2/unix/security/stunnel/

MAINTAINER=	martti.kuparinen@ericsson.com

BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay \
		${PREFIX}/lib/libssl.a:${PORTSDIR}/security/SSLeay \
		${PREFIX}/lib/libcrypto.a:${PORTSDIR}/security/SSLeay
RUN_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/stunnel
MAN8=		stunnel.8

.include <bsd.port.mk>
