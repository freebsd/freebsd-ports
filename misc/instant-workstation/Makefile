# New ports collection makefile for:	instant-workstation
# Date created:		12 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	instant-workstation
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.lemis.com/pub/

MAINTAINER=	grog@lemis.com

RUN_DEPENDS=	acroread:${PORTSDIR}/print/acroread4 \
		bash:${PORTSDIR}/shells/bash2 \
		cdrecord:${PORTSDIR}/sysutils/cdrtools \
		dos2unix:${PORTSDIR}/converters/unix2dos \
		emacs:${PORTSDIR}/editors/emacs20 \
		fetchmail:${PORTSDIR}/mail/fetchmail \
		gs:${PORTSDIR}/print/ghostscript-gnu \
		grip:${PORTSDIR}/audio/grip \
		gimp:${PORTSDIR}/graphics/gimp1 \
		gv:${PORTSDIR}/print/gv \
		gpg:${PORTSDIR}/security/gnupg \
		ispell:${PORTSDIR}/textproc/ispell \
		startkde:${PORTSDIR}/x11/kde3 \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		mount_smbfs:${PORTSDIR}/net/smbfs \
		mutt:${PORTSDIR}/mail/mutt \
		mozilla:${PORTSDIR}/www/mozilla \
		${LOCALBASE}/sbin/postfix:${PORTSDIR}/mail/postfix \
		xtset:${PORTSDIR}/x11/xtset \
		xmms:${PORTSDIR}/multimedia/xmms \
		xv:${PORTSDIR}/graphics/xv

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

.include <bsd.port.mk>
