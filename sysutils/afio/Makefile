# New ports collection makefile for:    afio
# Version required:     2.4.
# Date created:         4 October 1995
# Whom:                 Juergen Lock <nox@jelal.hb.north.de>
#
# $Id: Makefile,v 1.1.1.1 1995/08/25 10:04:31 asami Exp $
#

DISTNAME=       afio.2.4.1
PKGNAME=        afio-2.4.1
CATEGORIES+=    sysutils
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/system/Backup/ \
	ftp://ftp.win.tue.nl/pub/linux/tbackup/ \
	ftp://ftp.germany.eu.net/pub/os/Linux/Mirror.SunSITE/system/Backup/ \
	ftp://nic.funet.fi/pub/Linux/util/backup/ \
	ftp://medusa.k12.ar.us/pub/linux2/sunsite/system/Backup/
EXTRACT_SUFX=   .tgz

MAINTAINER=	nox@jelal.hb.north.de

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/afio.1
.endif

.include <bsd.port.mk>
