# New ports collection makefile for:   pfflowd
# Date created:        24 Feburary 2003
# Whom:                Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=	pfflowd
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	http://www.mindrot.org/files/pfflowd/

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	Convert pfsync states to NetFlow datagrams

MAN8=		pfflowd.8

PLIST_FILES=	sbin/pfflowd \
		etc/rc.d/pfflowd.sh.sample

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Only for 5.0 and above"
.endif

.if ${OSVERSION} < 502119
EXTRA_PATCHES+=	${FILESDIR}/pf34-Makefile
.endif

.if ${OSVERSION} < 502106
BUILD_DEPENDS=	${LOCALBASE}/include/pf/net/pfvar.h:${PORTSDIR}/security/pf
RUN_DEPENDS=	${LOCALBASE}/modules/pf.ko:${PORTSDIR}/security/pf
.endif

post-patch:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|g' < ${FILESDIR}/pfflowd.sh.sample \
		> ${WRKSRC}/pfflowd.sh.sample

pre-build:
	${CAT} ${FILESDIR}/pidfile.h > ${WRKSRC}/pidfile.h
	${CAT} ${FILESDIR}/pidfile.c > ${WRKSRC}/pidfile.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfflowd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pfflowd.8 ${PREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKSRC}/pfflowd.sh.sample ${PREFIX}/etc/rc.d/pfflowd.sh.sample

.include <bsd.port.post.mk>
