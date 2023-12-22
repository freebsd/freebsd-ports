PORTNAME=	jellyfin
DISTVERSION=	10.8.13
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/Thefrank/jellyfin-server-freebsd/releases/download/v${DISTVERSION}/
DISTFILES=	jellyfin-combined_${DISTVERSION}_freebsd-${ARCH}.tar.gz \
		libSkiaSharp.so
EXTRACT_ONLY=	jellyfin-combined_${DISTVERSION}_freebsd-${ARCH}.tar.gz

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Jellyfin Server Component with WebUI
WWW=		https://jellyfin.org/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		ffmpeg>0:multimedia/ffmpeg \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind \
		mediainfo>0:multimedia/mediainfo

USES=		sqlite:3 ssl:run
USE_RC_SUBR=	jellyfin

NO_BUILD=	YES

SUB_FILES=	jellyfin pkg-message
SUB_LIST=	DATADIR=${LOCALBASE}/jellyfin \
		GROUPS=${GROUPS} \
		USERS=${USERS}

NO_WRKSUBDIR=	YES
WRKSRC=		${WRKDIR}/jf

USERS=		jellyfin
GROUPS=		jellyfin

.include <bsd.port.options.mk>

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${LOCALBASE}/jellyfin "! ( -type f -name *\.so -or -type f -name "jellyfin" )"
	cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}/${LOCALBASE}/jellyfin " -type f -name "jellyfin" "
	${INSTALL_DATA} ${DISTDIR}/libSkiaSharp.so ${STAGEDIR}/${LOCALBASE}/jellyfin && ${INSTALL_DATA} ${WRKSRC}/*.so ${STAGEDIR}/${LOCALBASE}/jellyfin

#This can be done one of a number ways including: symlink, a .config override (using dllmap), or libmap.
post-install:
	@${ECHO_CMD} "libe_sqlite3.so libsqlite3.so" \
		>${STAGEDIR}${PREFIX}/etc/libmap.d/jellyfin.conf

.include <bsd.port.mk>
