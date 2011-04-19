# New ports collection makefile for:	mohawk
# Date created:		2011-04-15
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mohawk
PORTVERSION=	0.9
CATEGORIES=	www ipv6
MASTER_SITES=	http://files.etoilebsd.net/mohawk/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple and lightweight HTTP daemon

LICENSE=	BSD

MAN1=	mhtpasswd.1
MAN8=	mohawk.8

PLIST_FILES+=	bin/mhtpasswd \
		sbin/mohawk \
		etc/mohawk.conf.sample

USE_RC_SUBR=	mohawk

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 800502
BROKEN=		does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e '/.*rc.d\/mohawk.*/d' ${WRKSRC}/Makefile

post-install:
	@${INSTALL_DATA} ${WRKSRC}/mohawk.conf ${PREFIX}/etc/mohawk.conf.sample

.include <bsd.port.post.mk>
