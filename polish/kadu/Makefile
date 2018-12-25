# Created by: Jacek Pelka <jacek@combit.com.pl>
# $FreeBSD$

PORTNAME=	kadu
PORTVERSION=	4.3
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/:kadu \
		http://download.kadu.im/stable/:kadu \
		http://download.kadu.im/additions/:additions
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kadu
DIST_SUBDIR=	kadu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet communicator supporting Gadu-Gadu and Jabber/XMPP

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		pl-libgadu>=1.12.2:polish/libgadu
LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libsndfile.so:audio/libsndfile \
		libinjeqt.so:devel/injeqt \
		libqca-qt5.so:devel/qca@qt5 \
		libidn.so:dns/libidn \
		libqxmpp.so:net-im/qxmpp-qt5 \
		libgadu.so:polish/libgadu \
		libgcrypt.so:security/libgcrypt \
		libotr.so.5:security/libotr \
		libenchant.so:textproc/enchant
# TODO ntrack and ntrack-qt (needs porting) ?
# TODO separate ports for plugins and themes (possible starting with 0.10)

GG6_EMOTS_DISTFILE=	kompatybilne_z_GG6.tar.gz
GG7_EMOTS_DISTFILE=	dodatkowe_emoty_GG7.tar.gz

USES=		cmake:insource compiler:c++11-lib gettext-runtime \
		libarchive pkgconfig qt:5 readline tar:bzip2
USE_XORG=	x11 xext xfixes xscrnsaver
USE_GNOME=	glib20
USE_QT=		concurrent core dbus declarative gui multimedia network \
		script scripttools sql webkit widgets x11extras \
		xml xmlpatterns buildtools_build linguisttools_build \
		qmake_build imageformats_run sql-sqlite3_run
# Setting KADU_VERSION disables git invocation
CMAKE_ARGS=	-DKADU_VERSION:STRING="${DISTVERSION}" -DWITH_ENCHANT=ON \
		-DENABLE_TESTS=OFF
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=	GG_EMOTS
OPTIONS_SUB=	yes
GG_EMOTS_DESC=	GG-compatible emoticons

GG_EMOTS_DISTFILES=	${GG6_EMOTS_DISTFILE}:additions \
			${GG7_EMOTS_DISTFILE}:additions

post-patch:
	@${REINPLACE_CMD} '/kadu_add_test/ s|^|#|' \
		${WRKSRC}/kadu-core/plugin/CMakeLists.txt

post-install-GG_EMOTS-on:
	@${MKDIR} ${WRKSRC}/varia/themes/emoticons
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${TAR} -zxf ${_DISTDIR}/${GG6_EMOTS_DISTFILE} && \
	${MV} kompatybilne_z_GG6 gg6_compatible && \
	cd gg6_compatible && ${TAR} -zxf ${_DISTDIR}/${GG7_EMOTS_DISTFILE}
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${COPYTREE_SHARE} gg6_compatible ${STAGEDIR}${DATADIR}/themes/emoticons

.include <bsd.port.mk>
