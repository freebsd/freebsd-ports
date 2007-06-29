# New ports collection makefile for:	passlogd
# Date Created:				10 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	passlogd
PORTVERSION=	0.1f
CATEGORIES=	net
MASTER_SITES=	http://www.morphine.com/void/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Intercept and dump syslog remote log packets

PLIST_FILES=	sbin/passlogd

post-patch:
	${REINPLACE_CMD} -e "s|.(CXX)|${CC} ${CFLAGS}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/passlogd ${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
