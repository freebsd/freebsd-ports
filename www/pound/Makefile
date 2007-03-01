# New ports collection makefile for:	pound
# Date created:				27 August 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pound
PORTVERSION=	2.2
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Reverse proxy, load balancer and HTTP(S) frontend for web servers

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}.sh

SUB_LIST=	NAME=${PORTNAME}

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ARGS+=	F_CONF=${PREFIX}/etc/pound.cfg

MAN8=	pound.8 poundctl.8

OPTIONS=	DAEMON		"Running as a daemon" on \
		LOG		"With Syslog support" on \
		MSDAV		"With the Microsoft WebDAV extensions support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DAEMON)
CONFIGURE_ARGS+=	--disable-daemon
.endif

.if defined(WITHOUT_LOG)
CONFIGURE_ARGS+=	--without-log
.endif

.if defined(WITH_MSDAV)
CONFIGURE_ARGS+=	--enable-msdav
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
