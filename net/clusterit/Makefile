# New ports collection makefile for:	clusterit
# Date created:			4 February 1999
# Whom:				Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	clusterit
PORTVERSION=	2.0
CATEGORIES=	net devel
MASTER_SITES=	http://www.garbled.net/download/ \
		ftp://ftp.chg.ru/pub/prog/parallel/tools/clusterit/

MAINTAINER=	demon@FreeBSD.org

USE_XLIB=	yes

MAN1=		barrier.1 barrierd.1 dsh.1 jsh.1 jsd.1 rvt.1 dvt.1 \
		clustersed.1 run.1 seq.1 dshbak.1 pcp.1 pdf.1 prm.1

post-patch:
	@find ${WRKSRC} -name Makefile | xargs ${PERL} -pi -e 's#/usr/X11R6#${X11BASE}#g'

.include <bsd.port.mk>
