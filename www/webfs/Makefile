# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	webfs
PORTVERSION=	1.21
CATEGORIES=	www ipv6
MASTER_SITES=	http://dl.bytesex.org/releases/webfs/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple http server for static content

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USES=		gmake
MAKEFILE=	GNUmakefile

PLIST_FILES=	sbin/webfsd man/man1/webfsd.1

OPTIONS_DEFINE=		OPENSSL
OPENSSL_MAKE_ENV=	LDLIBS="-lssl -lcrypto" USE_DIET=no

MIMEFILE?=	${LOCALBASE}/etc/mime.types

USE_RC_SUBR=	webfsd

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/webfsd.man
.if empty(PORT_OPTIONS:MOPENSSL)
	@${REINPLACE_CMD} -e '/^USE_SSL.*:=/s/:=.*/:= no/' ${WRKSRC}/GNUmakefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/webfsd.man ${STAGEDIR}${PREFIX}/man/man1/webfsd.1

.include <bsd.port.mk>
