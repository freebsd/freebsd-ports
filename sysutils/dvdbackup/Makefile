# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dvdbackup
PORTVERSION=	0.4.2
PORTREVISION=	4
CATEGORIES=	sysutils multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Backup content from DVD to hard disk

LICENSE=	GPLv3

# See: https://bugs.launchpad.net/dvdbackup/+bug/1869226
BROKEN=		does not build with libdvdread 6.1.0

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread

GNU_CONFIGURE=	yes
USES=		gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	NEWS README

DEFAULT_DVD_DEVICE?=	/dev/cd0

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} "s|/dev/dvd|${DEFAULT_DVD_DEVICE}|g" \
		${WRKSRC}/src/main.c ${WRKSRC}/po/*.po ${WRKSRC}/po/*.pot \
		${WRKSRC}/README ${WRKSRC}/man/dvdbackup.1

pre-configure-DOCS-off:
	@${REINPLACE_CMD} 's|^install-data-am: .*|install-data-am: |' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
