# New ports collection makefile for:	mpd
# Version required:			1.0b5
# Date created:				16 May 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.7 1998/01/15 03:42:31 steve Exp $
#

DISTNAME=	mpd-1.0b5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.whistle.com/pub/archie/mpd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

OSVERSION!=	sysctl -n kern.osreldate

WRKSRC=		${WRKDIR}/mpd-1.0b5/src
ALL_TARGET=	depend all
MAN1=		mpd.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mpd ${PREFIX}/sbin/mpd
	@ ${INSTALL_MAN} ${WRKSRC}/mpd.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/etc/mpd
.for file in mpd.conf mpd.links mpd.script mpd.secret
	@ ${INSTALL_DATA} ${WRKSRC}/../conf/${file} ${PREFIX}/etc/mpd/${file}.sample
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/mpd
	@ ${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/mpd/README
.for file in CHANGES PROTOS EQL.patch README.code README.commands README.scripts README.server
	@ ${INSTALL_DATA} ${WRKSRC}/../docs/${file} ${PREFIX}/share/doc/mpd
.endfor
.endif

.include <bsd.port.mk>
