# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-rdp

COMMENT=	Remmina plugin for RDP protocol

BUILD_DEPENDS=	freerdp>=1.0.0:${PORTSDIR}/net/freerdp
RUN_DEPENDS=	${BUILD_DEPENDS}

MASTERDIR=	${.CURDIR}/../remmina-plugins

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
