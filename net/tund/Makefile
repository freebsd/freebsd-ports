# New ports collection makefile for:   tund
# Version required:    0.11
# Date created:        20 July 1999
# Whom:                Sergey Kosyakov <ks@itp.ac.ru>
#
# $FreeBSD$
#

DISTNAME=	tund-0.20
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.chg.ru/pub/networking/freebsd/

MAINTAINER=	ks@itp.ac.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/libcrypto.a:${PORTSDIR}/security/openssl

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
MAKE_ENV+=	EXTRA_SSL_LIBS="-lRSAglue -lrsaref"
.endif

MAN8=		tund.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
