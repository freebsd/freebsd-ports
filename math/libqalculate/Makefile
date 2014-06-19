# Created by: Sergey Akifyev <asa@agava.com>
# $FreeBSD$

PORTNAME=	libqalculate
PORTVERSION=	0.9.7
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/qalculate/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (backend library)

LIB_DEPENDS=	libcln.so:${PORTSDIR}/math/cln

USES=		pkgconfig pathfix gmake libtool
USE_GNOME=	glib20 intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENV=	GMSGFMT="${LOCALBASE}/bin/msgfmt"

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/libqalculate.pc.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libqalculate.so*

.include <bsd.port.mk>
