PORTNAME=	x11appjail
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	security

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Tool for creating, verifying, installing, and running AppJails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	appjail:sysutils/appjail \
		appscript:archivers/appscript \
		doas:security/doas \
		git:devel/git@lite \
		notify-send:devel/libnotify \
		su-exec:security/su-exec \
		unixexec:sysutils/unixexec \
		update-desktop-database:devel/desktop-file-utils \
		xauth:x11/xauth \
		xclipsync:sysutils/xclipsync \
		xdg-open:devel/xdg-utils \
		xdotool:x11/xdotool \
		Xephyr:x11-servers/xorg-server@xephyr \
		xev:x11/xev \
		xseticon:x11/xseticon \
		zenity:x11/zenity4

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	x11appjail

NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	@cd ${WRKSRC}/share/examples/x11appjail && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@for app in ${STAGEDIR}${EXAMPLESDIR}/Apps/*; do \
		${CHMOD} +x $${app}/build.sh; \
		${CHMOD} +x $${app}/create; \
		${CHMOD} +x $${app}/install; \
		${CHMOD} +x $${app}/run; \
		${CHMOD} +x $${app}/uninstall; \
		if [ -f "$${app}/X" ]; then ${CHMOD} +x $${app}/X; fi; \
		${CHMOD} +x $${app}/.reproduce/build.sh; \
	done

.include <bsd.port.mk>
