# New ports collection makefile for:	zebra
# Version required:	SNAP 981222
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.19 1999/07/18 11:52:13 andreas Exp $
#

DISTNAME=	zebra-0.74
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	andreas@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

post-install:
	@${ECHO} "===>     installing zebra startup file..."
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=" \
		< ${FILESDIR}/zebra.sh  \
		> ${PREFIX}/etc/rc.d/zebra.sh 
	@chmod 555 ${PREFIX}/etc/rc.d/zebra.sh
	@${ECHO} "===>     done."

.include <bsd.port.mk>
