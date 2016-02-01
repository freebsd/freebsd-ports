# Created by: Dima Sivachenko
# $FreeBSD$

PORTNAME=	clusterit
PORTVERSION=	2.5
CATEGORIES=	net devel parallel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Collection of clustering tools

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_USE=	XORG=x11

.include <bsd.port.options.mk>

post-patch-X11-off:
	${REINPLACE_CMD} -E 's,^(SUBDIRS) = .*,\1 = barrier dsh jsd pcp dtop tools,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
