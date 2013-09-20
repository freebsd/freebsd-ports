# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	packit
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://packit.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network auditing tool

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CPPFLAGS+=	`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`

MAN8=		packit.8
PLIST_FILES=	sbin/packit

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.if defined(WITHOUT_CAPTURE)
CONFIGURE_ARGS+=	--without-capture
.endif
.if defined(WITHOUT_INJECTION)
CONFIGURE_ARGS+=	--without-injection
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
