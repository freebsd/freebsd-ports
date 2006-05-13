# New ports collection makefile for:	xinetd
# Date created:				28 June 1996
# Whom:					markm
#
# $FreeBSD$
#

PORTNAME=	xinetd
PORTVERSION=	2.3.14
PORTREVISION=	0
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.xinetd.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for inetd with better control and logging

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes
ALL_TARGET=	build
CONFIGURE_ARGS+=	--with-loadavg --with-libwrap --with-ipv6
STARTUP_FILE=	${PREFIX}/etc/rc.d/xinetd.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN5=		xinetd.conf.5
MAN8=		xconv.8 xinetd.8 xinetd.log.8

post-patch:
	${FIND} ${WRKSRC}/libs/src -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's!\@INSTALL\@!/bin/cp!; s!-m 640!!'
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/xinetd/xconfig.h

pre-install:
	-@[ -f ${STARTUP_FILE} ] && \
	(${ECHO} "Remove old ${STARTUP_FILE} before install." && exit 1)

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/xinetd.sh.tmpl > ${STARTUP_FILE}
	@${CHMOD} 755 ${STARTUP_FILE}
	@${STRIP_CMD} ${PREFIX}/sbin/xinetd

.include <bsd.port.mk>
