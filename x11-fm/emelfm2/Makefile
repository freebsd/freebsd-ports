# $FreeBSD$

PORTNAME=	emelfm2
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://emelfm2.net/rel/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	The gtk2+ port of emelfm, a fast graphical filemanager

LICENSE=	GPLv3

USES=		gmake pkgconfig tar:bzip2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install

LDFLAGS+=	-lpthread
MAKE_ENV=	DOC_DIR="${DOCSDIR}/" \
		WITH_OUTPUTSTYLES=1 \
		WITH_CUSTOMMOUSE=1

DOCFILES=	ACTIONS CONFIGURATION CREDITS GPL HACKING INSTALL LGPL NEWS \
		README SPEC TODO USAGE WARNING

OPTIONS_DEFINE=		DEBUG DOCS GAMIN THUMB TRACKER HAL NLS
OPTIONS_DEFAULT=	GTK2
OPTIONS_RADIO=		GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_SUB=	yes

DEBUG_DESC=	Debugging messages
GAMIN_DESC=	Use Gamin for file monitoring
THUMB_DESC=	Thumbnail plugin
TRACKER_DESC=	Tracker-UI plugin
HAL_DESC=	Use HAL for automated device detection

DEBUG_MAKE_ENV=		DEBUG=1
GAMIN_USES=		fam:gamin
GAMIN_MAKE_ENV=		USE_GAMIN=1
GTK2_MAKE_ENV=		WITH_GTK2=1 WITH_GTK3=0
GTK2_USE=		GNOME=gtk20
GTK3_MAKE_ENV=		WITH_GTK2=0 WITH_GTK3=1
GTK3_USE=		GNOME=gtk30
THUMB_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp
THUMB_MAKE_ENV=		WITH_THUMB=1
TRACKER_MAKE_ENV=	WITH_TRACKER=1
NLS_USES=		gettext
NLS_INSTALL_TARGET=	install_i18n
HAL_MAKE_ENV=		WITH_HAL=1
HAL_LIB_DEPENDS=	libhal.so:sysutils/hal

post-patch:
# fix cross-arch compiling, which sets ${TARGET}
.for mfile in Makefile Makefile.config
	@${REINPLACE_CMD} -e 's|TARGET|BINTARGET|g' ${WRKSRC}/${mfile}
.endfor

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		PREFIX="${STAGEDIR}/${PREFIX}" \
		MAN_DIR="${STAGEDIR}${MAN1PREFIX}/man/man1" \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
