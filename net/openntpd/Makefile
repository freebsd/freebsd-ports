# New ports collection makefile for:	openntpd
# Date created:			2004-07-11
# Whom:				Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openntpd
PORTVERSION=	3.7p1
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenNTPD/ \
		ftp://ftp.kd85.com/pub/OpenBSD/OpenNTPD/ \
	 	ftp://ftp.jp.openbsd.org/pub/OpenBSD/OpenNTPD/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	OpenBSD's Network Time Protocol daemon

USE_RC_SUBR=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN5=		ntpd.conf.5
MAN8=		ntpd.8

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/ntpd.conf.5 ${WRKSRC}/ntpd.8
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		-e 's:%%RC_SUBR%%:${RC_SUBR}:g' \
		${FILESDIR}/openntpd.sh >${WRKDIR}/openntpd.sh

do-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ntpd.conf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/openntpd.sh ${PREFIX}/etc/rc.d
	@if [ ! -f ${PREFIX}/etc/ntpd.conf ]; then \
		${CP} -p ${EXAMPLESDIR}/ntpd.conf ${PREFIX}/etc; \
	fi

.include <bsd.port.mk>
