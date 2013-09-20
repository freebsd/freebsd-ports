# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squidclamav
PORTVERSION=	6.10
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Clamav c-icap service and redirector for Squid

LICENSE=	GPLv3

LIB_DEPENDS+=	icapapi:${PORTSDIR}/www/c-icap

GNU_CONFIGURE=	yes
CFLAGS+=	-DHAVE_STRNSTR

MAN1=		squidclamav.1

CONFIGURE_ARGS+=	--enable-shared --enable-static \
			--sysconfdir="${PREFIX}/etc/c-icap" \
			--with-c-icap=${LOCALBASE}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|CFGDIR=.*|CFGDIR="${PREFIX}/etc/c-icap"|g' \
		${WRKSRC}/configure.in ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/squidclamav.conf|${PREFIX}/etc/c\\-icap/squidclamav.conf|g' \
		${WRKSRC}/doc/squidclamav.1 ${WRKSRC}/src/squidclamav.h

.include <bsd.port.mk>
