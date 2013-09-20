# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	pfflowd
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	http://www.mindrot.org/files/pfflowd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert pfsync states to NetFlow datagrams

USE_RC_SUBR=	${PORTNAME}

MAN8=		pfflowd.8

PLIST_FILES=	sbin/pfflowd

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not compile
.endif

pre-build:
	${CAT} ${FILESDIR}/pidfile.h > ${WRKSRC}/pidfile.h
	${CAT} ${FILESDIR}/pidfile.c > ${WRKSRC}/pidfile.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfflowd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pfflowd.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
