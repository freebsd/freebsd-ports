# New ports collection makefile for:	giFT library
# Date created:		Fri Nov 16 02:47:45 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	giFT
PORTVERSION=	0.11.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	An OpenFT, Gnutella and FastTrack p2p network client

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		Magick.6:${PORTSDIR}/graphics/ImageMagick
.if defined(WITH_LIBMAGIC)
LIB_DEPENDS+=	magic.1:${PORTSDIR}/sysutils/file
.endif

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB	=yes
.if defined(WITH_LIBMAGIC)
CONFIGURE_ARGS=	--enable-libmagic
.endif

MAN1=	giftd.1

DOC_FILES=	AUTHORS COPYING src/ChangeLog \
		INSTALL NEWS QUICKSTART README TODO

post-patch:
	@${REINPLACE_CMD} -e \
	's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/lib/Makefile.in

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
