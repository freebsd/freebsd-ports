# New ports collection makefile for:	flow-tools
# Date created:				2000 Jul 25
# Whom:					@BABOLO <.@babolo.ru>
#
# $FreeBSD$
#

PORTNAME=	flow-tools
PORTVERSION=	0.55
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/ \
		ftp://ftp.fu-berlin.de/unix/network/flow-tools/

MAINTAINER=	.@babolo.ru

SCRIPTS=	flow-mirror flow-rsync flow-search

USE_GMAKE=	yes

GNU_CONFIGURE=	yes

MAN1=	flow-capture.1 flow-export.1 flow-stat.1 flow-cat.1 \
	flow-fanout.1 flow-tools.1 flow-dscan.1 flow-filter.1 \
	flow-print.1 flow-expire.1 flow-gen.1 flow-profile.1 \
	flow-mirror.1 flow-search.1

post-install:
.for i in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${i} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
