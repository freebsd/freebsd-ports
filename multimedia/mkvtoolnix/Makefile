# New ports collection makefile for:	mkvtoolnix
# Date created:		Tue Feb 24 02:09:12 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkvtoolnix
PORTVERSION=	0.8.7
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

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

# gcc 3.2 was available on 5.x before this OSVERSION
# do not build gcc 3.3 unless necessary
.if ${OSVERSION} < 501103
# use gcc 3.2
USE_GCC=3.2
.else
# default for 5.x series
USE_GCC=3.3
.endif

.if ${OSVERSION} < 500000
USE_GCC=2.95
# this is gcc 2.x
CFLAGS+= -DNO_WSTRING
.endif

.include <bsd.port.post.mk>
