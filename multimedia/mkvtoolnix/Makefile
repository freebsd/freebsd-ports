# New ports collection makefile for:	mkvtoolnix
# Date created:		Tue Feb 24 02:09:12 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkvtoolnix
PORTVERSION=	0.9.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

BROKEN=		Unfetchable

BUILD_DEPENDS=	${LOCALBASE}/lib/libmatroska.a:${PORTSDIR}/multimedia/libmatroska \
		${LOCALBASE}/lib/libebml.a:${PORTSDIR}/textproc/libebml
LIB_DEPENDS=	FLAC.5:${PORTSDIR}/audio/flac \
		expat.5:${PORTSDIR}/textproc/expat2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

MAN1=		base64tool.1 mkvextract.1 mkvinfo.1 mkvmerge.1

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.if ${OSVERSION} < 500000
CFLAGS+= -DNO_WSTRING
.endif

.include <bsd.port.post.mk>
