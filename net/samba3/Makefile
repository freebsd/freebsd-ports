# New ports collection makefile for:	samba
# Version required:			1.9.14
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.8 1995/11/27 04:05:31 asami Exp $
#

DISTNAME=	samba-1.9.15p6
CATEGORIES+=	net
MASTER_SITES=	ftp://nimbus.anu.edu.au/pub/tridge/samba/
WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAINTAINER=	gpalmer@FreeBSD.ORG

pre-install:
	@mkdir -p /usr/local/samba

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/smbstatus.1
	gzip -9nf ${PREFIX}/man/man1/smbclient.1
	gzip -9nf ${PREFIX}/man/man1/smbrun.1
	gzip -9nf ${PREFIX}/man/man1/smbtar.1
	gzip -9nf ${PREFIX}/man/man1/testparm.1
	gzip -9nf ${PREFIX}/man/man1/testprns.1
	gzip -9nf ${PREFIX}/man/man5/smb.conf.5
	gzip -9nf ${PREFIX}/man/man7/samba.7
	gzip -9nf ${PREFIX}/man/man8/smbd.8
	gzip -9nf ${PREFIX}/man/man8/nmbd.8
.endif

.include <bsd.port.mk>
