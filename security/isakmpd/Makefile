# New ports collection Makefile for:	ISAKMP daemon
# Date created:				Fri May 11 18:20:02 EEST 2001
# Whom:					Martti Kuparinen <martti.kuparinen@iki.fi>
#
# $FreeBSD$
#
# NOTE: See NetBSD's /usr/pkgsrc/security/isakmpd if this package
#       should be updated!
#

PORTNAME=	isakmpd
PORTVERSION=	20021118
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_NETBSD}
MASTER_SITE_SUBDIR=	LOCAL_PORTS

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
BROKEN=		"requires IPsec support"
.endif

USE_OPENSSL=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/isakmpd
MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

MAN5=		isakmpd.conf.5 isakmpd.policy.5
MAN8=		isakmpd.8
MANCOMPRESSED=	yes

post-patch:
	@(cd ${WRKSRC}; ${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" \
		conf.h ike_auth.c isakmpd.8 isakmpd.conf.5 \
		isakmpd.policy.5 policy.h)

.include <bsd.port.mk>
