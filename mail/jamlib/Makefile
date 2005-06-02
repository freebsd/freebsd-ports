# Ports collection makefile for:	jamlib
# Date created:		14 November 2002
# Whom:			CyrilM <cyrilm@tower.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	jamlib
PORTVERSION=	1.4.7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jamlib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A JAM subroutine library

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=	15
NO_INSTALL_MANPAGES=	yes
INSTALLS_SHLIB=	yes

MAN3=	JAM_AddEmptyMessage.3 \
	JAM_AddMessage.3 \
	JAM_ChangeMsgHeader.3 \
	JAM_ClearMsgHeader.3 \
	JAM_CloseMB.3 \
	JAM_Crc32.3 \
	JAM_CreateMB.3 \
	JAM_DelSubPacket.3 \
	JAM_DeleteMessage.3 \
	JAM_Errno.3 \
	JAM_FindUser.3 \
	JAM_GetMBSize.3 \
	JAM_GetSubfield.3 \
	JAM_GetSubfield_R.3 \
	JAM_LockMB.3 \
	JAM_NewSubPacket.3 \
	JAM_OpenMB.3 \
	JAM_PutSubfield.3 \
	JAM_ReadLastRead.3 \
	JAM_ReadMBHeader.3 \
	JAM_ReadMsgHeader.3 \
	JAM_ReadMsgText.3 \
	JAM_RemoveMB.3 \
	JAM_UnlockMB.3 \
	JAM_WriteLastRead.3 \
	JAM_WriteMBHeader.3 \
	jamlib.3

.include <bsd.port.mk>
