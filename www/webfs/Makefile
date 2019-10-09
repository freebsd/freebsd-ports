# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	webfs
PORTVERSION=	1.21
CATEGORIES=	www
MASTER_SITES=	http://dl.bytesex.org/releases/webfs/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple http server for static content

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USES=		gmake
MAKEFILE=	GNUmakefile

PLIST_FILES=	sbin/webfsd man/man1/webfsd.1.gz

OPTIONS_DEFINE=		OPENSSL
OPENSSL_MAKE_ENV=	LDLIBS="-lssl -lcrypto" USE_DIET=no

MIMEFILE?=	${LOCALBASE}/etc/mime.types

USE_RC_SUBR=	webfsd

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/webfsd.man

post-patch-OPENSSL-off:
	@${REINPLACE_CMD} -e '/^USE_SSL.*:=/s/:=.*/:= no/' ${WRKSRC}/GNUmakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/webfsd.man ${STAGEDIR}${PREFIX}/man/man1/webfsd.1

.include <bsd.port.mk>
