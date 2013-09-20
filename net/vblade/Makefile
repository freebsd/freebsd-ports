# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vblade
PORTVERSION=	21
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	aoetools/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Virtual EtherDrive(R) blade AoE target

MAKE_ARGS=	PLATFORM=freebsd\
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"\
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"\
		INSTALL_MAN="${INSTALL_MAN}"
MAKEFILE=	makefile
ALL_TARGET=

PLIST_FILES=	sbin/vblade sbin/vbladed
MAN8=		vblade.8

NO_STAGE=	yes
.include <bsd.port.mk>
