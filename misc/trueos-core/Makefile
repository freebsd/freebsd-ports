# $FreeBSD$

PORTNAME=	trueos-core
PORTVERSION=	201802221443
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	TrueOS Core Utilities

RUN_DEPENDS=	${LOCALBASE}/bin/pc-updatemanager:sysutils/pc-updatemanager \
		${LOCALBASE}/sbin/pc-sysinstall:sysutils/pc-sysinstall \
		${LOCALBASE}/share/trueos/scripts/functions.sh:sysutils/trueos-libsh \
		${LOCALBASE}/bin/lpreserver:sysutils/life-preserver \
		${LOCALBASE}/bin/sysadm-binary:sysutils/sysadm \
		${LOCALBASE}/sbin/beadm:sysutils/beadm \
		${LOCALBASE}/bin/rsync:net/rsync \
		${LOCALBASE}/bin/zfs-stats:sysutils/zfs-stats \
		${LOCALBASE}/sbin/anacron:sysutils/anacron \
		bsdstats>=0:sysutils/bsdstats \
		ataidle>=0:sysutils/ataidle \
		openntpd>=0:net/openntpd \
		pciutils>=0:sysutils/pciutils \
		pam_mkhomedir>=0:security/pam_mkhomedir \
		tor>=0:security/tor \
		bhyve-firmware>=0:sysutils/bhyve-firmware \
		dhcpcd>=0:net/dhcpcd

CONFLICTS=	pcbsd-utils-[0-9]*
WRKSRC_SUBDIR=	package-files
MAKE_ARGS=	STAGEDIR=${STAGEDIR} TYPE=core

USE_GITHUB=     yes
GH_ACCOUNT=     trueos
GH_PROJECT=     trueos-core
GH_TAGNAME=     2a4f26fcd46a5df1615ab1a120d6aeaa9f88ab65

.include <bsd.port.mk>
