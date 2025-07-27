PORTNAME=	minidlna
PORTVERSION=	1.3.3
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	net multimedia www

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Media-server compatible with "Digital Life Network Alliance"
WWW=		https://minidlna.sourceforge.net

LICENSE=	GPLv2

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3	\
		libexif.so:graphics/libexif	\
		libid3tag.so:audio/libid3tag	\
		libogg.so:audio/libogg		\
		libvorbis.so:audio/libvorbis	\
		libFLAC.so:audio/flac		\
		libavformat.so:multimedia/ffmpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-path=/var/db/minidlna \
		--with-os-url="http://www.FreeBSD.org"
USES=		autoreconf cpe gettext-tools iconv jpeg localbase

CPE_VENDOR=	minidlna_project

USE_GITHUB=	yes
GH_ACCOUNT=	glebius
GH_TAGNAME=	967337d

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message
USE_RC_SUBR=	minidlna
SUB_LIST+=	USER=${USERS}

USERS=	dlna
GROUPS=	dlna

OPTIONS_DEFINE=	DEBUG NLS
OPTIONS_SUB=	yes

DEBUG_CFLAGS=	-DDEBUG
NLS_USES=	gettext-runtime

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/*.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${STAGEDIR}${PREFIX}/etc/minidlna.conf.sample

.include <bsd.port.mk>
