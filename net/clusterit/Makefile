# New ports collection makefile for:	clusterit
# Date created:			4 February 1999
# Whom:				Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	clusterit
PORTVERSION=	2.5
CATEGORIES=	net devel parallel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of clustering tools

GNU_CONFIGURE=	yes

MAN1=		barrier.1 barrierd.1 clustersed.1 dsh.1 dshbak.1 \
		dtop.1 jsh.1 jsd.1 pcp.1 pdf.1 prm.1 rseq.1 run.1

.if defined (WITHOUT_X11)
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
MAN1+=		rvt.1 dvt.1
USE_XORG=	x11
.endif

post-patch:
.if defined(WITHOUT_X11)
	${REINPLACE_CMD} -E 's,^(SUBDIRS) = .*,\1 = barrier dsh jsd pcp dtop tools,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
