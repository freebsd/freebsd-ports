# ex:ts=8
# Ports collection makefile for:  fping
# Date created:			  Tue Mar 25, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	fping
PORTVERSION=	2.4b2
CATEGORIES=	net ipv6
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/
#MASTER_SITES=	http://www.fping.com/download/
PKGNAMESUFFIX=	+ipv6
DISTNAME=	${PORTNAME}-${PORTVERSION}_to-ipv6

MAINTAINER=	jharris@widomaker.com
COMMENT=	Quickly ping N hosts w/o flooding the network - IPv6 version

PLIST_FILES=	sbin/fping6

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/sbin"
MAN8=		fping.8
USE_DOS2UNIX=	fping.8

# IPv6 enabled since it is a IPv6 only version
CFLAGS+=	-DIPV6

post-patch:
	@${REINPLACE_CMD} -e 's/fping@/${MAINTAINER:S/@/\\@/g} or fping@/g' \
		${WRKSRC}/fping.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fping ${PREFIX}/sbin/fping6
	@${CHMOD} 4555 ${PREFIX}/sbin/fping6
	${INSTALL_MAN} ${WRKSRC}/fping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
