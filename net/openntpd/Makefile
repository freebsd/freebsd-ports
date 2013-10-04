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

post-extract:
	@${CP} ${FILESDIR}/compat.h ${FILESDIR}/adjfreq.c ${WRKSRC}

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/ntpd.h ${WRKSRC}/ntpd.conf.5 ${WRKSRC}/ntpd.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${STAGEDIR}${PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/ntpd.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
