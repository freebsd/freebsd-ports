# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	5
CATEGORIES?=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Additional plugins and scripts for some KDE applications

RUN_DEPENDS=	${ATLANTIKDESIGNER_DEP}:${PORTSDIR}/games/atlantikdesigner \
		${KADDRESSBOOKPLUG_DEP}:${PORTSDIR}/misc/kaddressbook-plugins \
		${KATEPLUGINS_DEP}:${PORTSDIR}/editors/kate-plugins \
		${KFILEPLUGINS_DEP}:${PORTSDIR}/misc/kfile-plugins \
		${KICKERAPPLETS_DEP}:${PORTSDIR}/misc/kicker-applets \
		${KNEWSTICKERAPP_DEP}:${PORTSDIR}/misc/knewsticker-scripts \
		${KONQPLUGINS_DEP}:${PORTSDIR}/misc/konq-plugins \
		${KSIG_DEP}:${PORTSDIR}/misc/ksig \
		${NOATUNPLUG_DEP}:${PORTSDIR}/multimedia/noatun-plugins \
		${RENAMEDLGPLUG_DEP}:${PORTSDIR}/misc/renamedlgplugins

NO_BUILD=	yes
USE_KDELIBS_VER=3
_NO_KDE_FIXPTHREAD=yes

.if make(package)
DEPENDS_TARGET="package"
.endif # .if make(package)

do-install:	# empty
	${DO_NADA}

.include "${.CURDIR}/Makefile.split"
.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
