# New ports collection makefile for:	clusterit
# Date created:			4 February 1999
# Whom:				Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	clusterit
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	net devel parallel
MASTER_SITES=	http://www.garbled.net/download/ \
		ftp://ftp.chg.ru/pub/prog/parallel/clusterit/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of clustering tools

MAN1=		barrier.1 barrierd.1 dsh.1 jsh.1 jsd.1 \
		clustersed.1 run.1 seq.1 dshbak.1 pcp.1 pdf.1 prm.1

.if defined (WITHOUT_X11)
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
MAN1+=		rvt.1 dvt.1
USE_XLIB=	yes
.endif
USE_PERL5_BUILD=yes

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${PERL} -pi -e 's#/usr/X11R6#${X11BASE}#g'
.for file in command.c rvt.c screen.c
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/rvt/${file}
.endfor
.if defined(WITHOUT_X11)
	@${PERL} -pi -e 's#rvt dvt##g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
