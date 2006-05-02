# New ports collection makefile for:	ncplib
# Date created:		9 Dec 1999
# Whom:			Boris Popov <bp@butya.kz>
#
# $FreeBSD$
#

PORTNAME=	ncplib
PORTVERSION=	1.3.4
CATEGORIES=	net
MASTER_SITES=	http://rbp.chat.ru/pub/nwlib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilites to work with Novell NetWare servers

.if !exists(/usr/src/sys/kern/vnode_if.src)
IGNORE=		requires kernel source
.endif

MANCOMPRESSED=	yes

MAN1=	ncpasswd.1 ncprint.1 ncpsend.1 ncpurge.1
MAN8=	ipxping.8 ncpsvc.8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
