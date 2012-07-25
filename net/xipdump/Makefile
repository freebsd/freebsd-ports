# New ports collection makefile for:	xipdump
# Date created:				17 Jun 2001
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	xipdump
PORTVERSION=	1.5.4
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.lse.epita.fr/twiki/pub/Projects/XipDump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Displays IP packets using X window

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

USE_XORG=	xt x11 ice xaw xmu
GNU_CONFIGURE=	yes
LDFLAGS+=	`${LIBNET_CONFIG} --libs`
CFLAGS+=	`${LIBNET_CONFIG} --cflags` `${LIBNET_CONFIG} --defines` \
		-I/usr/include

PLIST=	${WRKDIR}/PLIST

MAN8=	xipdump.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-build:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST})
	@${ECHO_CMD} "@dirrm share/xipdump/pkt" >> ${PLIST}
	@${ECHO_CMD} "@dirrm share/xipdump/pkc" >> ${PLIST}
	@${ECHO_CMD} "@dirrm share/xipdump" >> ${PLIST}

.include <bsd.port.mk>
