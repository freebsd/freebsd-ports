# New ports collection makefile for:	djmount
# Date created:		15 October 2008
# Whom:			Eric L. Chen <d9364104@mail.nchu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	djmount
PORTVERSION=	0.71
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	d9364104@mail.nchu.edu.tw
COMMENT=	Mount UPnP A/V Media

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		upnp.6:${PORTSDIR}/devel/upnp
BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

BROKEN=		does not compile

PLIST_FILES=	bin/${PORTNAME}
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-fuse-prefix=${LOCALBASE} \
		--with-external-libupnp --with-libupnp-prefix=${LOCALBASE}

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
