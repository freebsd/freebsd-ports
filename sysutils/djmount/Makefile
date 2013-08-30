# Created by: Eric L. Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	djmount
PORTVERSION=	0.71
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	eric@camachat.org
COMMENT=	Mount UPnP A/V Media

LIB_DEPENDS=	upnp.9:${PORTSDIR}/devel/upnp
BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

PLIST_FILES=	bin/${PORTNAME}
GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
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
