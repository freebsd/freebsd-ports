# New ports collection makefile for:	webfs
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	webfs
PORTVERSION=	1.21
PORTREVISION=	0
CATEGORIES=	www ipv6
MASTER_SITES=	http://dl.bytesex.org/releases/webfs/

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	A simple http server for static content

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
.if !defined(WITHOUT_OPENSSL)
MAKE_ENV=	USE_SSL=no
.endif
MAKE_ENV+=	LDLIBS="-lssl -lcrypto" USE_DIET=no

MAN1=		webfsd.1
MIMEFILE?=	${LOCALBASE}/etc/mime.types

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 400000
BROKEN=		"Requires FreeBSD 4.x or greater due to ipv6 support"
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "==========================================="
	@${ECHO_CMD} "This package supports the following option:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " -DWITHOUT_SSL   - omit SSL support"
	@${ECHO_CMD} "==========================================="
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/webfsd.man
.if defined(WITHOUT_OPENSSL)
	@${REINPLACE_CMD} -e 's|USE_SSL      := yes|USE_SSL      := no|' ${WRKSRC}/Make.config
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.man ${PREFIX}/man/man1/webfsd.1

.include <bsd.port.post.mk>
