# New ports collection makefile for:	openvas-plugins
# Date created:		2008-04-27
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-plugins
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/588/

MAINTAINER=	cherry@trombik.org
COMMENT=	Plugins for OpenVAS

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet \
		openvasd:${PORTSDIR}/security/openvas-server
LIB_DEPENDS=	openvas.2:${PORTSDIR}/security/openvas-libraries \
		openvasnasl.2:${PORTSDIR}/security/openvas-libnasl \
		gnutls.40:${PORTSDIR}/security/gnutls
RUN_DEPENDS=	openvasd:${PORTSDIR}/security/openvas-server \
		${LOCALBASE}/bin/gmd5sum:${PORTSDIR}/sysutils/coreutils \
		${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync

GNU_CONFIGURE=	yes
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config
CPPFLAGS+=	"`${LIBNET_CONFIG} --cflags`"

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../openvas-libraries/Makefile.common"

#.if ${ARCH} != "i386"
#BROKEN=		does not compile
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${WRKSRC}/plugins/3com_hub/Makefile

.include <bsd.port.post.mk>
