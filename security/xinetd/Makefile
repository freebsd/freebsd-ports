# New ports collection makefile for:	xinetd
# Date created:				28 June 1996
# Whom:					markm
#
# $FreeBSD$
#

PORTNAME=	xinetd
PORTVERSION=	2.3.12
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.xinetd.org/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Replacement for inetd with better control and logging

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	build
CONFIGURE_ARGS+=	--with-loadavg --with-libwrap --with-ipv6

MAN5=		xinetd.conf.5
MAN8=		xconv.8 xinetd.8 xinetd.log.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500029
EXTRA_PATCHES!= ${ECHO_CMD} ${PKGDIR}/files.5/patch-*
.endif

post-patch:
	${FIND} ${WRKSRC}/libs/src -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's!\@INSTALL\@!/bin/cp!; s!-m 640!!'
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' < ${WRKSRC}/xinetd/xconfig.h \
		> ${WRKSRC}/xinetd/xconfig.h.new
	@${MV} ${WRKSRC}/xinetd/xconfig.h.new ${WRKSRC}/xinetd/xconfig.h

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO_CMD} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/xinetd.sh ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi
	@${STRIP_CMD} ${PREFIX}/sbin/xinetd

.include <bsd.port.post.mk>
