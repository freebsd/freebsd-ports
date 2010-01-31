# New ports collection makefile for:	desktop-config
# Date created:		2009-12-29
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	desktop-installer
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://jbacon.dyndns.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Quickly configure a FreeBSD desktop system

NO_BUILD=	yes

MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Doc/${PORTNAME}.1 ${PREFIX}/man/man1
	${MKDIR} ${DATADIR}
	${CP} -r ${WRKSRC}/Data/* ${DATADIR}

.include <bsd.port.pre.mk>
post-patch:
	${REINPLACE_CMD} 's|/etc/mtree|$${PORTSDIR=/usr/ports}/Templates|' \
		${WRKSRC}/${PORTNAME}
	${REINPLACE_CMD} \
		's|DATADIR=Data|DATADIR=${PREFIX}/share/desktop-installer|g' \
		${WRKSRC}/desktop-installer

.include <bsd.port.post.mk>
