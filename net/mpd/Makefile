# New ports collection makefile for:	mpd
# Version required:			1.0b4
# Date created:				16 May 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.6 1998/01/11 18:02:33 steve Exp $
#

DISTNAME=		mpd-1.0b4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.whistle.com/pub/archie/mpd/
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

OSVERSION!=     sysctl -n kern.osreldate

WRKSRC=			${WRKDIR}/mpd-1.0b4/src
ALL_TARGET=		depend all
MAN1=			mpd.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mpd ${PREFIX}/sbin/mpd
	@ ${INSTALL_MAN} ${WRKSRC}/mpd.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/etc/mpd
.for file in mpd.conf mpd.links mpd.script mpd.secret
	@ ${INSTALL_DATA} ${WRKSRC}/../conf/${file} ${PREFIX}/etc/mpd/${file}.sample
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/mpd
	@ ${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/mpd/README
.for file in CHANGES PROTOS README.code README.commands README.scripts
	@ ${INSTALL_DATA} ${WRKSRC}/../docs/${file} ${PREFIX}/share/doc/mpd
.endfor

.include <bsd.port.mk>
