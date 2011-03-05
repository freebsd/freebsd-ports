# Ports collection makefile for:	libkate
# Date created:				Sat 19 Oct 2008
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libkate
PORTVERSION=	0.3.7
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Codec for karaoke and text encapsulation for Ogg

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	ogg.7:${PORTSDIR}/audio/libogg \
		png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

CFLAGS+=	"-I${LOCALBASE}/include"

MAN1=	kateenc.1 katedec.1

OPTIONS=	DOXYGEN "Build docs with doxygen (requires TeX, QT, etc.)" off \
		HTMLDOCS "Install bundled html documentation" off

PORTDOCS=	*

.include <bsd.port.pre.mk>

.ifdef(WITH_DOXYGEN)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s|^(katepcdir =).*|\1 ${LOCALBASE}/libdata/pkgconfig|" \
	${WRKSRC}/Makefile.in

post-install:
.for f in ${MAN1}
	${INSTALL_MAN}  ${WRKSRC}/doc/man/${f}  ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in README AUTHORS COPYING THANKS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
. if defined(WITH_HTMLDOCS)
	${CP} -RPpn ${WRKSRC}/doc/html ${DOCSDIR}/html
. endif
.endif

.include <bsd.port.post.mk>
