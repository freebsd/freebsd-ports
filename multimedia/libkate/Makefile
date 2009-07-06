# Ports collection makefile for:	libkate
# Date created:				Sat 19 Oct 2008
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libkate
PORTVERSION=	0.1.12
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Codec for karaoke and text encapsulation for Ogg

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	ogg.6:${PORTSDIR}/audio/libogg \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include"

MAN1=	kateenc.1 katedec.1

OPTIONS=	DOXYGEN "Build docs with doxygen (requires TeX, QT, etc.)" off

.include <bsd.port.pre.mk>

.ifdef(WITH_DOXYGEN || exists(${LOCALBASE}/bin/doxygen))
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s|^(katepcdir =).*|\1 ${LOCALBASE}/libdata/pkgconfig|" \
	${WRKSRC}/Makefile.in
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]*SUBDIRS[[:space:]]*=.*)doc|\1|' \
		${BUILD_WRKSRC}/Makefile.in
.endif

post-install:
.ifdef(NOPORTDOCS)
.for f in ${MAN1}
	${INSTALL_MAN}  ${WRKSRC}/doc/man/${f}  ${PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.post.mk>
