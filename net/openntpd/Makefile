# $FreeBSD$

PORTNAME=	openntpd
PORTVERSION=	4.6
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenNTPD
EXTRACT_SUFX=	.tgz

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	OpenBSD's Network Time Protocol daemon

USERS=		_ntp
GROUPS=		_ntp

USE_RC_SUBR=	openntpd

WRKSRC=		${WRKDIR}/ntpd

MAN5=		ntpd.conf.5
MAN8=		ntpd.8

post-extract:
.for i in compat.h adjfreq.c
	@${CP} ${FILESDIR}/$i ${WRKSRC}
.endfor

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/ntpd.h ${WRKSRC}/ntpd.conf.5 ${WRKSRC}/ntpd.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/ntpd.conf ${EXAMPLESDIR}
	@if [ ! -f ${PREFIX}/etc/ntpd.conf ]; then \
	    ${CP} ${EXAMPLESDIR}/ntpd.conf ${PREFIX}/etc; \
	fi

.include <bsd.port.mk>
