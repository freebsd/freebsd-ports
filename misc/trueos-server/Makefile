# $FreeBSD$

PORTNAME=	trueos-server
PORTVERSION=	201707111915
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	TrueOS Server

RUN_DEPENDS=	${LOCALBASE}/bin/pc-updatemanager:sysutils/pc-updatemanager \
		${LOCALBASE}/sbin/pc-sysinstall:sysutils/pc-sysinstall \
		${LOCALBASE}/share/trueos/scripts/functions.sh:sysutils/trueos-libsh \
		${LOCALBASE}/bin/lpreserver:sysutils/life-preserver \
		${LOCALBASE}/bin/sysadm-binary:sysutils/sysadm \
		${LOCALBASE}/sbin/beadm:sysutils/beadm \
		${LOCALBASE}/bin/sudo:security/sudo \
		${LOCALBASE}/bin/zsh:shells/zsh \
		${LOCALBASE}/bin/rsync:net/rsync \
		${LOCALBASE}/bin/screen:sysutils/screen \
		${LOCALBASE}/bin/tmux:sysutils/tmux \
		${LOCALBASE}/bin/nano:editors/nano \
		${LOCALBASE}/bin/zfs-stats:sysutils/zfs-stats \
		bsdstats>=0:sysutils/bsdstats \
		ataidle>=0:sysutils/ataidle \
		openntpd>=0:net/openntpd \
		bhyve-firmware>=0:sysutils/bhyve-firmware \
		dhcpcd>=0:net/dhcpcd

CONFLICTS=	pcbsd-utils-[0-9]* trueos-desktop-[0-9]*
WRKSRC_SUBDIR=	xtrafiles
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=     yes
GH_ACCOUNT=     trueos
GH_PROJECT=     trueos-core
GH_TAGNAME=     6acd0c75d0c94c94a96c07f26c04ef553ad8ea90

.include <bsd.port.mk>
