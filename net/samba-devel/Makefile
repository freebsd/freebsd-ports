# New ports collection makefile for:	samba
# Version required:			1.9.15p8
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.10 1996/03/01 00:37:45 gpalmer Exp $
#

DISTNAME=	samba-1.9.15p8
CATEGORIES=	net
MASTER_SITES=	ftp://nimbus.anu.edu.au/pub/tridge/samba/
WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAINTAINER=	gpalmer@FreeBSD.ORG

MAN1=		smbstatus.1 smbclient.1 smbrun.1 smbtar.1 testparm.1 testprns.1
MAN5=		smb.conf.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8

pre-install:
	@${MKDIR} /usr/local/samba

.include <bsd.port.mk>
