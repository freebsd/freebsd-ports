# New ports collection makefile for:	webfs
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	webfs
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://bytesex.org/misc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	A simple http server for static content

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
.if !defined(WITHOUT_OPENSSL)
MAKE_ENV=	USE_SSL=no
.endif
MAKE_ENV+=	LDLIBS="-lssl -lcrypto" USE_DIET=no

MAN1=		webfsd.1
MIMEFILE?=	${PREFIX}/etc/webfsd/mime.types

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

do-configure:
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/webfsd.man
.if defined(WITHOUT_OPENSSL)
	@${REINPLACE_CMD} -e 's|USE_SSL      := yes|USE_SSL      := no|' ${WRKSRC}/Make.config
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.man ${PREFIX}/man/man1/webfsd.1
.if !exists(${PREFIX}/etc/webfsd/mime.types)
	@${MKDIR} ${PREFIX}/etc/webfsd
	@${ECHO_CMD} "# Insert mime types here" > ${PREFIX}/etc/webfsd/mime.types
.endif

.include <bsd.port.post.mk>
