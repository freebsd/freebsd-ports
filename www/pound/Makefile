# New ports collection makefile for:	pound
# Date created:				27 August 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pound
PORTVERSION=	2.4.3
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

POUND_CFLAGS=	${CFLAGS}
POUND_LDFLAGS=	${LDFLAGS}
MAKE_ARGS+=	F_CONF=${PREFIX}/etc/pound.cfg

MAN8=	pound.8 poundctl.8

OPTIONS=	DAEMON		"Running as a daemon" on \
		LIBTHR		"Link against libthr for threading" on \
		LOG		"With Syslog support" on \
		MSDAV		"With the Microsoft WebDAV extensions support" off \
		PCRE		"Build with libpcre support" off

.include <bsd.port.pre.mk>

PORTDOCS=	README FAQ CHANGELOG

.if defined(WITHOUT_DAEMON)
CONFIGURE_ARGS+=	--disable-daemon
.endif

.if defined(WITHOUT_LOG)
CONFIGURE_ARGS+=	--disable-log
.endif

.if defined(WITH_MSDAV)
CONFIGURE_ARGS+=	--enable-msdav
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
POUND_CFLAGS+=		"-I${LOCALBASE}/include"
POUND_LDFLAGS+=		"-L${LOCALBASE}/lib"
.endif

.if !defined(WITHOUT_LIBTHR)
PTHREAD_LIBS=		-lthr
.endif

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CFLAGS="${POUND_CFLAGS}" \
		CPPFLAGS="${POUND_CFLAGS}" \
		LDFLAGS="${POUND_LDFLAGS}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
