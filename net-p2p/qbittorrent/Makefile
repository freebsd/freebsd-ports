# New ports collection makefile for:	qbittorrent
# Date created:				2007-04-01
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
PORTVERSION=	1.3.3
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bittorrent client written in C++ / Qt4 using libtorrent

LIB_DEPENDS=	ccext2-1.6.0:${PORTSDIR}/devel/commoncpp \
		execinfo.1:${PORTSDIR}/devel/libexecinfo \
		zzip.13:${PORTSDIR}/devel/zziplib \
		curl.5:${PORTSDIR}/ftp/curl \
		torrent-rasterbar.3:${PORTSDIR}/net-p2p/rblibtorrent-devel

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network xml \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--with-libtorrent-inc="${LOCALBASE}/include" \
		--with-libtorrent-lib="${LOCALBASE}/lib" \
		--with-libcurl-inc="${LOCALBASE}/include" \
		--with-libcurl-lib="${LOCALBASE}/lib" \
		--with-libzzip-inc="${LOCALBASE}/include" \
		--with-libzzip-lib="${LOCALBASE}/lib"
INSTALLS_ICONS=	yes

MAN1=		qbittorrent.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$$$PREFIX/share/man|${MANPREFIX}/man|' \
		${WRKSRC}/src/src.pro
	@${ECHO_CMD} "LIBS+= -lexecinfo" >> ${WRKSRC}/src/src.pro

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent

.include <bsd.port.post.mk>
