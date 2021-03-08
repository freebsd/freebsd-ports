# $FreeBSD$

PORTNAME=	onedrive
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.10
CATEGORIES=	net

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	OneDrive Free client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ldc2:lang/ldc
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify
RUN_DEPENDS=	${LOCALBASE}/sbin/logrotate:sysutils/logrotate

USES=		autoreconf gmake pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	abraunegg

GNU_CONFIGURE=	yes
PKGCONFIG=		pkgconf

OPTIONS_DEFINE=		DOCS NOTIFY COMPLETION
OPTIONS_DEFAULT=	NOTIFY COMPLETION
OPTIONS_SUB=		yes

NOTIFY_CONFIGURE_ENABLE=	notifications
NOTIFY_USES=		gnome
NOTIFY_USE=		GNOME=glib20,gdkpixbuf2
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

COMPLETION_DESC=		Install completion for BASH, FISH and ZSH
COMPLETION_CONFIGURE_ENABLE=	completions
COMPLETION_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
COMPLETION_RUN_DEPENDS=		bash-completion>0:shells/bash-completion

ONEDRIVE_LOGDIR=	/var/log/${PORTNAME}

PORTDOCS=	*

post-extract:
	${CP} ${FILESDIR}/freebsd_inotify.d ${WRKSRC}/src

post-install:
	${INSTALL} -d -m 0775 ${STAGEDIR}${ONEDRIVE_LOGDIR}

.include <bsd.port.mk>
