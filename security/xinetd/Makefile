# New ports collection makefile for:	xinetd
# Date created:				28 June 1996
# Whom:					markm
#
# $FreeBSD$
#

PORTNAME=	xinetd
PORTVERSION=	2.3.8
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	http://www.xinetd.org/

MAINTAINER=	vanilla@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	build
CONFIGURE_ARGS+=	--with-loadavg --with-libwrap

MAN5=		xinetd.conf.5
MAN8=		xconv.8 xinetd.8 xinetd.log.8

post-patch:
	${FIND} ${WRKSRC}/libs/src -name Makefile.in | ${XARGS} \
		${PERL} -pi -e 's!\@INSTALL\@!/bin/cp!; s!-m 640!!'
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' < ${WRKSRC}/xinetd/xconfig.h \
		> ${WRKSRC}/xinetd/xconfig.h.new
	@${MV} ${WRKSRC}/xinetd/xconfig.h.new ${WRKSRC}/xinetd/xconfig.h

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO_CMD} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/xinetd.sh ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi
	@${STRIP_CMD} ${PREFIX}/sbin/xinetd

.include <bsd.port.mk>
