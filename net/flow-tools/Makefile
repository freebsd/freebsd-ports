# New ports collection makefile for:	flow-tools
# Date created:				2000 Jul 25
# Whom:					@BABOLO <.@babolo.ru>
#
# $FreeBSD$
#

PORTNAME=	flow-tools
PORTVERSION=	0.56
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	.@babolo.ru

SCRIPTS=	flow-mirror flow-rsync flow-search

USE_GMAKE=	yes

GNU_CONFIGURE=	yes

MAN1=	flow-capture.1 flow-gen.1 flow-split.1 flow-cat.1	\
	flow-header.1 flow-stat.1 flow-dscan.1 flow-import.1	\
	flow-tools-examples.1 flow-expire.1 flow-merge.1	\
	flow-tools.1 flow-export.1 flow-print.1 flow-xlate.1	\
	flow-fanout.1 flow-receive.1 flow-filter.1 flow-send.1

post-patch:
	${TOUCH} -r ${WRKSRC}/configure.in.orig ${WRKSRC}/configure.in
	${TOUCH} -r ${WRKSRC}/configure.orig ${WRKSRC}/configure

pre-build:
	${RM} ${WRKSRC}/src/ftbuild.h

post-install:
.for i in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${i} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
