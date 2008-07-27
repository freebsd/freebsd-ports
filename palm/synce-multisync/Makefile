# New ports collection makefile for:   synce-multisync
# Date created:                September 2004
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	synce-multisync_plugin
PORTVERSION=	0.9.0
PORTREVISION=	8
CATEGORIES=	palm deskutils
MASTER_SITES=	SF/synce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SynCE synchronisation plugin for Multisync

LIB_DEPENDS=	rra.0:${PORTSDIR}/palm/synce-librra \
		synce.0:${PORTSDIR}/palm/synce-libsynce
BUILD_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync
RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync

USE_GNOME=	gnomeprefix gnometarget gnomevfs2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-librapi=${LOCALBASE} \
			--with-libsynce=${LOCALBASE} \
			--with-librra=${LOCALBASE} \
			--with-multisync-include=${LOCALBASE}/include/multisync
CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

BROKEN=		No longer supported by developers
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2008-08-24

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
