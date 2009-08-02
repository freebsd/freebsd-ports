# Ports collection makefile for:	sdcv
# Date created:			2005/07/07
# Whom:				chinsan <chinsan.tw@gmail.com>
# $FreeBSD$
#

PORTNAME=	sdcv
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A text-based utility for work with dictionaries in StarDict's format

USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	glib20
SUB_FILES=	pkg-message

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		sdcv.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Doesn't build on 64-bit platforms
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/doc/sdcv.1
	@${REINPLACE_CMD} -e '1425 s, install-data,,' \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's, getopt.h,,g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '146 s|()|(int, char * const [], const char *)|g' \
		${WRKSRC}/src/getopt.h
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/sdcv.cpp
	@${REINPLACE_CMD} -e 's,@mandir@/uk,@mandir@,' \
		${WRKSRC}/doc/uk/Makefile.in
.if !defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's,@USE_NLS@,yes,g' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's, getopt.h,,g; s,@USE_NLS@,yes,g' \
		${WRKSRC}/src/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
