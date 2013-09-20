# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	sdcv
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text-based utility for work with dictionaries in StarDict's format

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20
USES=		pkgconfig iconv
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		sdcv.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/doc/sdcv.1
	@${REINPLACE_CMD} -e '1425 s, install-data,,' \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's, getopt.h,,g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '146 s|()|(int, char * const [], const char *)|g' \
		${WRKSRC}/src/getopt.h
.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
	@${REINPLACE_CMD} -e '516 s|sizeof|(guint32)sizeof|g' \
		${WRKSRC}/src/lib/lib.cpp
.endif
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/sdcv.cpp
	@${REINPLACE_CMD} -e 's,@mandir@/uk,@mandir@,' \
		${WRKSRC}/doc/uk/Makefile.in
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's,@USE_NLS@,yes,g' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's, getopt.h,,g; s,@USE_NLS@,yes,g' \
		${WRKSRC}/src/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
