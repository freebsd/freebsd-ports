# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	sing
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	net-mgmt security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/${PORTVERSION}
DISTNAME=	SING-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for sending customized ICMP packets

LICENSE=	GPLv2

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libpcap-prefix=/usr
CONFIGURE_ENV=	LIBS="`${LIBNET_CONFIG} --libs`"
CPPFLAGS+=	`${LIBNET_CONFIG} --defines` \
		`${LIBNET_CONFIG} --cflags`
MAN8=		sing.8
PLIST_FILES=	sbin/sing

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

NO_STAGE=	yes
post-extract:
	@${RM} -rf ${WRKSRC}/libpcap-* ;\
	${RM} -rf ${WRKSRC}/Libnet-*

.include <bsd.port.mk>
