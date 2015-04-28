# New ports collection makefile for:	pcbsd-meta-kde
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-kde
PORTVERSION=	1429798531
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-kde

RUN_DEPENDS=	kdelibs>=0:${PORTSDIR}/x11/kdelibs4 \
		kde-baseapps>=0:${PORTSDIR}/x11/kde4-baseapps \
		kde-workspace>=0:${PORTSDIR}/x11/kde4-workspace \
		kde-runtime>=0:${PORTSDIR}/x11/kde4-runtime \
		kdeadmin>=0:${PORTSDIR}/sysutils/kdeadmin4 \
		kdeplasma-addons>=0:${PORTSDIR}/deskutils/kdeplasma-addons \
		kdeutils>=0:${PORTSDIR}/misc/kdeutils4 \
		ksnapshot>=0:${PORTSDIR}/graphics/ksnapshot \
		py27-qt4>=0:${PORTSDIR}/devel/py-qt4 \
		gtk-qt-engine>=0:${PORTSDIR}/x11-themes/gtk-qt4-engine \
		kdebindings>=0:${PORTSDIR}/devel/kdebindings4 \
		lineakd>=0:${PORTSDIR}/sysutils/lineakd \
		plasma-scriptengine-python>=0:${PORTSDIR}/x11/plasma-scriptengine-python \
		plasma-scriptengine-ruby>=0:${PORTSDIR}/x11/plasma-scriptengine-ruby \
		plasma-applet-daisy>=0:${PORTSDIR}/deskutils/plasma-applet-daisy \
		plasma-applet-panelspacer>=0:${PORTSDIR}/deskutils/plasma-applet-panelspacer \
		plasma-applet-simpleweatherforecast>=0:${PORTSDIR}/deskutils/plasma-applet-simpleweatherforecast \
		kde4-style-qtcurve>=0:${PORTSDIR}/x11-themes/qtcurve-kde4 \
		lirc>=0:${PORTSDIR}/comms/lirc \
		k3b>=0:${PORTSDIR}/sysutils/k3b-kde4 \
		kio-audiocd>=0:${PORTSDIR}/audio/kio-audiocd \
		en-hunspell>=0:${PORTSDIR}/textproc/en-hunspell \
		kdeartwork>=0:${PORTSDIR}/x11-themes/kdeartwork4 \
		djbfft>=0:${PORTSDIR}/math/djbfft

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
