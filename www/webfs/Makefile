# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	webfs
PORTVERSION=	1.21
CATEGORIES=	www ipv6
MASTER_SITES=	http://dl.bytesex.org/releases/webfs/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A simple http server for static content

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USES=		gmake
MAKEFILE=	GNUmakefile
.if !defined(WITHOUT_OPENSSL)
MAKE_ENV=	USE_SSL=no
.endif
MAKE_ENV+=	LDLIBS="-lssl -lcrypto" USE_DIET=no

PLIST_FILES=	sbin/webfsd

MAN1=		webfsd.1
MIMEFILE?=	${LOCALBASE}/etc/mime.types

USE_RC_SUBR=	webfsd

NO_STAGE=	yes
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

.include <bsd.port.mk>
