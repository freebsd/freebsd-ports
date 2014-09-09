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

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libpcap-prefix=/usr
CPPFLAGS+=	`${LIBNET_CONFIG} --defines` \
		`${LIBNET_CONFIG} --cflags`
LIBS+=		`${LIBNET_CONFIG} --libs`
PLIST_FILES=	sbin/sing \
		man/man8/sing.8.gz

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-extract:
	@${RM} -rf ${WRKSRC}/libpcap-* ;\
	${RM} -rf ${WRKSRC}/Libnet-*

.include <bsd.port.mk>
