# Created by: Dima Sivachenko
# $FreeBSD$

PORTNAME=	clusterit
PORTVERSION=	2.5
CATEGORIES=	net devel parallel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of clustering tools

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined (WITHOUT_X11)
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
USE_XORG=	x11
.endif

post-patch:
.if defined(WITHOUT_X11)
	${REINPLACE_CMD} -E 's,^(SUBDIRS) = .*,\1 = barrier dsh jsd pcp dtop tools,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
