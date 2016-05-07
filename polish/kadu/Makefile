# Created by: Jacek Pelka <jacek@combit.com.pl>
# $FreeBSD$

PORTNAME=	kadu
PORTVERSION=	2.1
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/:kadu \
		GOOGLE_CODE:kadu \
		http://download.kadu.im/stable/:kadu \
		http://download.kadu.im/additions/:additions
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kadu
DIST_SUBDIR=	kadu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Internet communicator supporting Gadu-Gadu and Jabber/XMPP

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		pl-libgadu>=1.12.1:polish/libgadu
LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libsndfile.so:audio/libsndfile \
		libinjeqt.so:devel/injeqt \
		libqca-qt5.so:devel/qca-qt5 \
		libidn.so:dns/libidn \
		libgadu.so:polish/libgadu \
		libotr.so.5:security/libotr \
		libenchant.so:textproc/enchant
# TODO ntrack and ntrack-qt (needs porting) ?
# TODO separate ports for plugins and themes (possible starting with 0.10)

GG6_EMOTS_DISTFILE=	kompatybilne_z_GG6.tar.gz
GG7_EMOTS_DISTFILE=	dodatkowe_emoty_GG7.tar.gz

USES=		cmake compiler:c++11-lib execinfo libarchive pkgconfig tar:bzip2
USE_XORG=	xscrnsaver
CMAKE_ARGS=	-DKADU_VERSION:STRING="${DISTVERSION}" -DWITH_ENCHANT=ON
# Setting KADU_VERSION disables git invocation

USE_QT5=	buildtools_build concurrent dbus declarative gui multimedia \
		network script scripttools webkit x11extras phonon4 \
		xml linguisttools_build qmake_build imageformats_run \
		sql-sqlite3_run
LDFLAGS+=	-lexecinfo
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GG_EMOTS
OPTIONS_SUB=	yes
GG_EMOTS_DESC=	GG-compatible emoticons

GG_EMOTS_DISTFILES=	${GG6_EMOTS_DISTFILE}:additions \
			${GG7_EMOTS_DISTFILE}:additions

post-install-GG_EMOTS-on:
	@${MKDIR} ${WRKSRC}/varia/themes/emoticons
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${TAR} -zxf ${_DISTDIR}/${GG6_EMOTS_DISTFILE} && \
	${MV} kompatybilne_z_GG6 gg6_compatible && \
	cd gg6_compatible && ${TAR} -zxf ${_DISTDIR}/${GG7_EMOTS_DISTFILE}
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${COPYTREE_SHARE} gg6_compatible ${STAGEDIR}${DATADIR}/themes/emoticons

.include <bsd.port.mk>
