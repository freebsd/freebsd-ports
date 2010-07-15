# New ports collection makefile for: ifstated
# Date created:         18 November 2004
# Whom:                 Matthew George <mdg@secureworks.net>
#
# $FreeBSD$
#

PORTNAME=	ifstated
PORTVERSION=	4.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://christianserving.org/ports/net/ifstated/

MAINTAINER=	ports@christianserving.org
COMMENT=	Interface state daemon

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

MAN5=		ifstated.conf.5
MAN8=		ifstated.8

PLIST_FILES=	etc/ifstated.conf-sample \
		sbin/ifstated
SUB_FILES=	pkg-message

USE_RC_SUBR=	ifstated

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/ifstated.c ${WRKSRC}/ifstated.8 ${WRKSRC}/ifstated.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifstated ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ifstated.conf-sample ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/ifstated.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ifstated.8 ${PREFIX}/man/man8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
