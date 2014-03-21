# Created by: Jacek Pelka <jacek@combit.com.pl>
# $FreeBSD$

PORTNAME=	kadu
PORTVERSION=	0.12.3
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/:kadu \
		GOOGLE_CODE:kadu \
		http://download.kadu.im/stable/:kadu \
		http://download.kadu.im/additions/:additions
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:kadu
DIST_SUBDIR=	kadu
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Internet communicator supporting Gadu-Gadu and Jabber/XMPP

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		pl-libgadu>=1.11.1:${PORTSDIR}/polish/libgadu
LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libqca.so:${PORTSDIR}/devel/qca \
		libidn.so:${PORTSDIR}/dns/libidn \
		libgadu.so:${PORTSDIR}/polish/libgadu \
		libenchant.so:${PORTSDIR}/textproc/enchant
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl
# TODO enable devel/libexecinfo
# TODO ntrack and ntrack-qt (needs porting) ?
# TODO separate ports for plugins and themes (possible starting with 0.10)

GG6_EMOTS_DISTFILE=	kompatybilne_z_GG6.tar.gz
GG7_EMOTS_DISTFILE=	dodatkowe_emoty_GG7.tar.gz

USES=		cmake pkgconfig tar:bzip2
USE_XORG=	xscrnsaver
CMAKE_ARGS=	-DKADU_VERSION:STRING="${DISTVERSION}" -DWITH_ENCHANT=ON
# Setting KADU_VERSION disables git invocation

USE_QT4=	dbus gui network phonon script scripttools webkit xml \
		linguist_build moc_build qmake_build rcc_build uic_build \
		imageformats_run sql-sqlite3_run
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GG_EMOTS
OPTIONS_SUB=	yes
GG_EMOTS_DESC=	GG-compatible emoticons

GG_EMOTS_DISTFILES=	${GG6_EMOTS_DISTFILE}:additions \
			${GG7_EMOTS_DISTFILE}:additions

.include <bsd.port.options.mk>

.if ${OSVERSION} > 1000051
LDFLAGS+=	-lexecinfo
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/plugins/single_window/CMakeLists.txt \
		${WRKSRC}/plugins/tabs/CMakeLists.txt
	@${FIND} ${WRKSRC} -exec ${GREP} -q "#!/bin/bash" {} \; \
		-exec ${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|g' {} \;
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/plugins/sql_history/storage/sql-restore.cpp

post-install:
.if ${PORT_OPTIONS:MGG_EMOTS}
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${TAR} -zxf ${_DISTDIR}/${GG6_EMOTS_DISTFILE} && \
	${MV} kompatybilne_z_GG6 gg6_compatible && \
	cd gg6_compatible && ${TAR} -zxf ${_DISTDIR}/${GG7_EMOTS_DISTFILE}
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${COPYTREE_SHARE} gg6_compatible ${STAGEDIR}${DATADIR}/themes/emoticons
.endif

.include <bsd.port.mk>
