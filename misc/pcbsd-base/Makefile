# Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-base
PORTVERSION=	20160514
PORTEPOCH=	2
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Base system packages

RUN_DEPENDS=	${LOCALBASE}/bin/qsudo:sysutils/pcbsd-utils-qt5 \
		${LOCALBASE}/bin/pc-updatemanager:sysutils/pc-updatemanager \
		${LOCALBASE}/sbin/pc-sysinstall:sysutils/pc-sysinstall \
		${LOCALBASE}/bin/pc-su:sysutils/pcbsd-utils \
                ${LOCALBASE}/share/pcbsd/scripts/functions.sh:sysutils/pcbsd-libsh \
		${LOCALBASE}/bin/sysadm-binary:sysutils/sysadm \
		${LOCALBASE}/bin/sysadm-client:sysutils/sysadm-client \
		${LOCALBASE}/bin/lpreserver:sysutils/life-preserver \
		${LOCALBASE}/bin/jobctl:sysutils/jobd \
		${LOCALBASE}/bin/git:devel/git \
		${LOCALBASE}/sbin/beadm:sysutils/beadm \
		${LOCALBASE}/sbin/anacron:sysutils/anacron \
		${LOCALBASE}/bin/xv:graphics/xv \
		${LOCALBASE}/etc/rc.d/fail2ban:security/py-fail2ban \
		${LOCALBASE}/bin/zip:archivers/zip \
		${LOCALBASE}/bin/unzip:archivers/unzip \
		${LOCALBASE}/bin/sudo:security/sudo \
		${LOCALBASE}/bin/cdrdao:sysutils/cdrdao \
		${LOCALBASE}/bin/growisofs:sysutils/dvd+rw-tools \
		${LOCALBASE}/bin/ssh-askpass:security/openssh-askpass \
		${LOCALBASE}/bin/xdg-open:devel/xdg-utils \
		${LOCALBASE}/bin/rsync:net/rsync \
		${LOCALBASE}/bin/pwcview:multimedia/pwcview \
		${LOCALBASE}/bin/rar:archivers/rar \
		${LOCALBASE}/bin/system-config-printer:print/system-config-printer \
		${LOCALBASE}/bin/numlockx:x11/numlockx \
		${LOCALBASE}/bin/gpg:security/gnupg \
		${LOCALBASE}/bin/xvkbd:x11/xvkbd \
		${LOCALBASE}/bin/unrar:archivers/unrar \
		${LOCALBASE}/bin/7z:archivers/p7zip \
		${LOCALBASE}/bin/avahi-browse:net/avahi-app \
		${LOCALBASE}/bin/gsmartcontrol:sysutils/gsmartcontrol \
		${LOCALBASE}/bin/xsane:graphics/xsane \
		${LOCALBASE}/bin/rdesktop:net/rdesktop \
		${LOCALBASE}/bin/fluxbox:x11-wm/fluxbox \
		xorg>=0:x11/xorg \
		xf86-input-synaptics>=0:x11-drivers/xf86-input-synaptics \
		xf86-video-intel>=0:x11-drivers/xf86-video-intel \
		xf86-video-scfb>=0:x11-drivers/xf86-video-scfb \
		noto>=0:x11-fonts/noto \
		droid-fonts-ttf>=0:x11-fonts/droid-fonts-ttf \
		libvdpau>=0:multimedia/libvdpau \
		gtk2-qtcurve-theme>=0:x11-themes/qtcurve-gtk2 \
		qt4-style-qtcurve>=0:x11-themes/qtcurve-qt4 \
		gtk-theme-switch>=0:x11/gtk-theme-switch2 \
		alsa-lib>=0:audio/alsa-lib \
		fluxbox-tenr-styles-pack>=0:x11-themes/fluxbox-tenr-styles-pack \
		vorbis-tools>=0:audio/vorbis-tools \
		cups-pdf>=0:print/cups-pdf \
		cups-filters>=0:print/cups-filters \
		cups-bjnp>=0:print/cups-bjnp \
		foomatic-db>=0:print/foomatic-db \
		gutenprint-cups>=0:print/gutenprint-cups \
		fusefs-ntfs>=0:sysutils/fusefs-ntfs \
		nss_mdns>=0:dns/nss_mdns \
		cursor-jimmac-theme>=0:x11-themes/cursor-jimmac-theme \
		cuse4bsd-kmod>=0:multimedia/cuse4bsd-kmod \
		webcamd>=0:multimedia/webcamd \
		pciutils>=0:sysutils/pciutils \
		linux_dvbwrapper-kmod>=0:multimedia/linux_dvbwrapper-kmod \
		volman>=0:sysutils/volman \
		fribidi>=0:converters/fribidi \
		libdvdcss>=0:multimedia/libdvdcss \
		pam_ldap>=0:security/pam_ldap \
		pam_mkhomedir>=0:security/pam_mkhomedir \
		nss_ldap>=0:net/nss_ldap \
		rpm2cpio>=0:archivers/rpm2cpio \
		libaacs>=0:multimedia/libaacs \
		xbrightness>=0:x11/xbrightness \
		x11vnc>=0:net/x11vnc \
		ataidle>=0:sysutils/ataidle \
		tk84>=0:x11-toolkits/tk84 \
		tk85>=0:x11-toolkits/tk85 \
		tk86>=0:x11-toolkits/tk86 \
		pulseaudio>=0:audio/pulseaudio \
		paprefs>=0:audio/paprefs \
		pavucontrol>=0:audio/pavucontrol \
		disktype>=0:sysutils/disktype \
		openntpd>=0:net/openntpd \
		socat>=0:net/socat \
		tor>=0:security/tor

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
