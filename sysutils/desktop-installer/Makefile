# New ports collection makefile for:	desktop-installer
# Date created:		2009-12-29
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	desktop-installer
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Quickly configure a FreeBSD desktop system

RUN_DEPENDS=	auto-append-line:${PORTSDIR}/sysutils/auto-admin

NO_BUILD=	yes

MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Doc/${PORTNAME}.man \
		${PREFIX}/man/man1/${PORTNAME}.1
	${MKDIR} ${DATADIR}
	${CP} -r ${WRKSRC}/Data/* ${DATADIR}
	${MKDIR} ${DATADIR}/Scripts
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DATADIR}/Scripts

.include <bsd.port.pre.mk>
post-patch:
	${REINPLACE_CMD} 's|/etc/mtree|$${PORTSDIR=/usr/ports}/Templates|' \
		${WRKSRC}/${PORTNAME}
	${REINPLACE_CMD} \
		's|DATADIR=Data|DATADIR=${PREFIX}/share/desktop-installer|g' \
		${WRKSRC}/desktop-installer

.include <bsd.port.post.mk>
