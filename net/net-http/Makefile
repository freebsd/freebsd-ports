# ex:ts=8
# New ports collection makefile for:	net-http
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	net-http
PORTVERSION=	0.3.1
CATEGORIES=	net scheme
# mastersite disappeared around September 2002
MASTER_SITES=	# http://evan.prodromou.san-francisco.ca.us/software/net-http/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for doing HTTP client-side programming in Guile

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

.include <bsd.port.pre.mk>

GUILE_VER!=	(cd ${PORTSDIR}/lang/guile && make -V GUILE_VER)
PLIST_SUB=	GUILE_VER="${GUILE_VER}"

do-install:
	${CP} -R ${WRKSRC}/net/ ${LOCALBASE}/share/guile/${GUILE_VER}/net/

.include <bsd.port.post.mk>
