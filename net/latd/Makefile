# Created by: Tillman Hodgson <tillman@seekingfire.com>
# $FreeBSD$

PORTNAME=	latd
PORTVERSION=	1.31
CATEGORIES=	net
MASTER_SITES=	SF/linux-decnet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Linux-DECnet project LAT protocol suite

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

MAN1=		llogin.1
MAN5=		latd.conf.5
MAN8=		latd.8 latcp.8 moprc.8
PLIST_FILES=	bin/llogin etc/latd.conf.sample sbin/latcp sbin/latd sbin/moprc

NO_STAGE=	yes
post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -e \
		'/<utmp.h>/s|^|// |'

.include <bsd.port.mk>
