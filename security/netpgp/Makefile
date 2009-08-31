# New ports collection makefile for:	netpgp
# Date created:		2009-05-27
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	netpgp
PORTVERSION=	20090611
CATEGORIES=	security
MASTER_SITES=	NETBSD/LOCAL_PORTS

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	PGP signing, verification, encryption and decryption program

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-DOPENSSL_NO_IDEA

MAN1+=		netpgp.1 \
		netpgpkeys.1 \
		netpgpverify.1
MAN3+=		libnetpgp.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.x.
.endif

.include <bsd.port.post.mk>
