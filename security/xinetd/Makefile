# New ports collection makefile for:	xinetd
# Date created:				28 June 1996
# Whom:					markm
#
# $FreeBSD$
#

PORTNAME=	xinetd
PORTVERSION=	2.3.14
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.xinetd.org/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Replacement for inetd with better control and logging

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	xinetd
ALL_TARGET=	build
CONFIGURE_ARGS+=	--with-loadavg --with-libwrap --with-ipv6

MAN5=		xinetd.conf.5
MAN8=		xconv.8 xinetd.8 xinetd.log.8

post-patch:
	${FIND} ${WRKSRC}/libs/src -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's!\@INSTALL\@!/bin/cp!; s!-m 640!!'
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/xinetd/xconfig.h

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/xinetd

.include <bsd.port.mk>
