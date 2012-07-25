# New ports collection makefile for:   latd
# Date created:        19 December 2003
# Whom:                Tillman Hodgson <tillman@seekingfire.com>
#
# $FreeBSD$
#

PORTNAME=	latd
PORTVERSION=	1.29
CATEGORIES=	net
MASTER_SITES=	SF/linux-decnet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Linux-DECnet project LAT protocol suite

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		llogin.1
MAN5=		latd.conf.5
MAN8=		latd.8 latcp.8 moprc.8
PLIST_FILES=	bin/llogin etc/latd.conf.sample sbin/latcp sbin/latd sbin/moprc

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -e \
		'/<utmp.h>/s|^|// |'

.include <bsd.port.mk>
