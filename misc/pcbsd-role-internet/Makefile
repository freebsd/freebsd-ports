# New ports collection makefile for:	pcbsd-role-internet
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-internet
PORTVERSION=	1416511068
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes internet connectivity software

RUN_DEPENDS=	pidgin>=0:${PORTSDIR}/net-im/pidgin \
		emesene>=0:${PORTSDIR}/net-im/emesene \
		echat>=0:${PORTSDIR}/net-im/echat \
		qbittorrent>=0:${PORTSDIR}/net-p2p/qbittorrent \
		filezilla>=0:${PORTSDIR}/ftp/filezilla \
		lftp>=0:${PORTSDIR}/ftp/lftp \
		chromium>=0:${PORTSDIR}/www/chromium \
		firefox>=0:${PORTSDIR}/www/firefox

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
