# New ports collection makefile for:	xinetd
# Date created:				28 June 1996
# Whom:					markm
#
# $FreeBSD$
#

PORTNAME=	xinetd
PORTVERSION=	2.3.3
CATEGORIES=	security
MASTER_SITES=	http://www.xinetd.org/

MAINTAINER=	vanilla@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	build
CONFIGURE_ARGS+=	--with-loadavg --with-libwrap
# --with-inet6 "ipv6's code seens buggy.."

MAN5=		xinetd.conf.5
MAN8=		xinetd.8 xinetd.log.8

post-patch:
.for dir in sio str misc xlog pset pq timer
	${PERL} -pi -e 's!\@INSTALL\@!/bin/cp!; s!-m 640!!' \
		${WRKSRC}/libs/src/${dir}/Makefile.in
.endfor

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/xinetd.sh ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi
	strip ${PREFIX}/sbin/xinetd

.include <bsd.port.mk>
