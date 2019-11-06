# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vblade
PORTVERSION=	21
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/aoetools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Virtual EtherDrive(R) blade AoE target

BROKEN=		unfetchable

MAKE_ARGS=	PLATFORM=freebsd\
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"\
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"\
		INSTALL_MAN="${INSTALL_MAN}"
MAKEFILE=	makefile
ALL_TARGET=
USES=		tar:tgz

PLIST_FILES=	sbin/vblade sbin/vbladed man/man8/vblade.8.gz

.include <bsd.port.mk>
