# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.9.2
PORTEPOCH=		1
CATEGORIES=		polish net-im
MASTER_SITES=		http://www.kadu.net/download/stable/:kadu \
			http://www.kadu.net/download/additions/:additions
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:kadu
DIST_SUBDIR=		kadu
EXTRACT_ONLY=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		pawel@FreeBSD.org
COMMENT=		QT Gadu-Gadu / Jabber client

LICENSE=		GPLv2

BUILD_DEPENDS=		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=		enchant.1:${PORTSDIR}/textproc/enchant \
			gadu.3:${PORTSDIR}/polish/libgadu \
			idn:${PORTSDIR}/dns/libidn \
			qca.2:${PORTSDIR}/devel/qca \
			sndfile.1:${PORTSDIR}/audio/libsndfile
RUN_DEPENDS=		qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl
# TODO enable devel/libexecinfo
# TODO ntrack and ntrack-qt (needs porting) ?
# TODO separate ports for plugins and themes (possible starting with 0.10)

GG6_EMOTS_DISTFILE=	kompatybilne_z_GG6.tar.gz
GG7_EMOTS_DISTFILE=	dodatkowe_emoty_GG7.tar.gz

USE_BZIP2=		yes
USE_CMAKE=		yes
USE_XORG=		xscrnsaver
CMAKE_ARGS=		-DENABLE_AUTODOWNLOAD:BOOL=OFF \
			-DKADU_VERSION:STRING="${DISTVERSION}" \
			-DWITH_ENCHANT=ON
# Setting KADU_VERSION disables git invocation
CMAKE_USE_PTHREAD=	yes

USE_QT_VER=		4
QT_COMPONENTS=		gui dbus network script webkit xml qmake_build \
			linguist_build moc_build rcc_build uic_build \
			imageformats_run sql-sqlite3_run
WANT_GNOME=		yes
INSTALLS_ICONS=		yes

MAKE_JOBS_UNSAFE=	yes

OPTIONS=	GG_EMOTS	"Install GG-compatible emoticons"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GG_EMOTS)
PLIST_SUB+=	GG_EMOTS=""
DISTFILES+=	${GG6_EMOTS_DISTFILE}:additions \
		${GG7_EMOTS_DISTFILE}:additions
.else
PLIST_SUB+=	GG_EMOTS="@comment "
.endif

KADU_SHARED_MODULES+=	spellchecker qt4_sound
KADU_DISABLED_MODULES=	alsa_sound amarok1_mediaplayer audacious_mediaplayer mediaplayer

post-patch:
	@${FIND} ${WRKSRC} -exec ${GREP} -q "#!/bin/bash" {} \; \
		-exec ${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|g' {} \;
.for module in ${KADU_DISABLED_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=.|module_${module}=n|g' ${WRKSRC}/.config
.endfor
.for module in ${KADU_SHARED_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=.|module_${module}=m|g' ${WRKSRC}/.config
.endfor
.for module in ${KADU_STATIC_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=.|module_${module}=y|g' ${WRKSRC}/.config
.endfor
.if defined(WITH_GG_EMOTS)
	@${REINPLACE_CMD} -e 's|emoticons_gg6_compatible=n|emoticons_gg6_compatible=y|g' ${WRKSRC}/.config
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${TAR} -zxf ${_DISTDIR}/${GG6_EMOTS_DISTFILE} && \
	${MV} kompatybilne_z_GG6 gg6_compatible && \
	cd gg6_compatible && ${TAR} -zxf ${_DISTDIR}/${GG7_EMOTS_DISTFILE}
.endif

.include <bsd.port.post.mk>
