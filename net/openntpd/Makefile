# New ports collection makefile for:	openntpd
# Date created:			2004-07-11
# Whom:				Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openntpd
PORTVERSION=	4.4
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenNTPD
EXTRACT_SUFX=	.tgz

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	OpenBSD's Network Time Protocol daemon

USE_RC_SUBR=	openntpd

WRKSRC=		${WRKDIR}/ntpd
MAKE_JOBS_SAFE=	yes

MAN5=		ntpd.conf.5
MAN8=		ntpd.8

.include <bsd.port.pre.mk>

# requires adjtime(NULL, &olddelta) by unprivileged user
.if ${OSVERSION} < 700000
IGNORE=		is unsupported prior to FreeBSD 7.0
.endif

post-extract:
.for i in compat.h adjfreq.c arc4random.c
	@${CP} ${FILESDIR}/$i ${WRKSRC}
.endfor

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/ntpd.h ${WRKSRC}/ntpd.conf.5 ${WRKSRC}/ntpd.8

do-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/ntpd.conf ${EXAMPLESDIR}
	@if [ ! -f ${PREFIX}/etc/ntpd.conf ]; then \
		${CP} ${EXAMPLESDIR}/ntpd.conf ${PREFIX}/etc; \
	fi

.include <bsd.port.post.mk>
