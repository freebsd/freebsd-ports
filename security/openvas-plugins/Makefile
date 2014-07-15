# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-plugins
PORTVERSION=	1.0.7
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/588/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugins for OpenVAS

BUILD_DEPENDS=	openvasd:${PORTSDIR}/security/openvas-server
LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet \
		libopenvas.so:${PORTSDIR}/security/openvas-libraries \
		libopenvasnasl.so:${PORTSDIR}/security/openvas-libnasl \
		libgnutls.so:${PORTSDIR}/security/gnutls
RUN_DEPENDS=	openvasd:${PORTSDIR}/security/openvas-server \
		${LOCALBASE}/bin/gmd5sum:${PORTSDIR}/sysutils/coreutils \
		${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	"`${LIBNET_CONFIG} --cflags`" -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${WRKSRC}/plugins/3com_hub/Makefile

.include <bsd.port.mk>
