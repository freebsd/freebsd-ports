# $FreeBSD$

PORTNAME=	onedrive
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	OneDrive Free client

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify
BUILD_DEPENDS=	ldc2:lang/ldc
RUN_DEPENDS=	${LOCALBASE}/sbin/logrotate:sysutils/logrotate

USES=		gmake pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	abraunegg

PKGCONFIG=		pkgconf
MAKE_ARGS=		DC=ldc2
INSTALL_TARGET=		install.noservice

OPTIONS_DEFINE=		DOCS NOTIFY BASH ZSH
OPTIONS_DEFAULT=	DOCS NOTIFY BASH ZSH
OPTIONS_SUB=		yes

DOCFILES=		README.md README.Office365.md config CHANGELOG.md

NOTIFY_VARS=		NOTIFICATIONS=1
NOTIFY_USES=		gnome
NOTIFY_USE=		GNOME=glib20
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

BASH_COMPLETION_DIR=	${LOCALBASE}/share/bash-completion/completions
ZSH_COMPLETION_DIR=	${LOCALBASE}/share/zsh/site-functions

post-extract:
	${CP} ${FILESDIR}/freebsd_inotify.d ${WRKSRC}/src

do-install-DOCS-on:
.for f in ${DOCFILES}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${BASH_COMPLETION_DIR}
	${INSTALL_DATA} ${WRKSRC}/completions/complete.bash \
		${STAGEDIR}${BASH_COMPLETION_DIR}/onedrive

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${ZSH_COMPLETION_DIR}
	${INSTALL_DATA} ${WRKSRC}/completions/complete.zsh \
		${STAGEDIR}${ZSH_COMPLETION_DIR}/_onedrive

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/onedrive.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
