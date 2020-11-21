# $FreeBSD$

PORTNAME=	onedrive
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.7
CATEGORIES=	net

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	OneDrive Free client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify
BUILD_DEPENDS=	ldc2:lang/ldc
RUN_DEPENDS=	${LOCALBASE}/sbin/logrotate:sysutils/logrotate

USES=		autoreconf gmake pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	abraunegg

GNU_CONFIGURE=	yes
PKGCONFIG=		pkgconf

OPTIONS_DEFINE=		NOTIFY COMPLETION
OPTIONS_DEFAULT=	NOTIFY COMPLETION
OPTIONS_SUB=		yes

NOTIFY_CONFIGURE_ENABLE=	notifications
NOTIFY_USES=		gnome
NOTIFY_USE=		GNOME=glib20,gdkpixbuf2
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

COMPLETION_DESC=	Install completion for BASH, FISH and ZSH
COMPLETION_CONFIGURE_ENABLE=	completions

ONEDRIVE_LOGDIR=	/var/log/${PORTNAME}

post-extract:
	${CP} ${FILESDIR}/freebsd_inotify.d ${WRKSRC}/src

post-install:
	${INSTALL} -d -m 0775 ${STAGEDIR}${ONEDRIVE_LOGDIR}

.include <bsd.port.mk>
