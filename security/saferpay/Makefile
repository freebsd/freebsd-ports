# New ports collection makefile for:	saferpay
# Date created:		06 September 2001
# Whom:			mb@imp.ch
#
# $FreeBSD$
#

PORTNAME=	saferpay
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.saferpay.com/download/
DISTFILES=	${PORTNAME}_${PORTVERSION}_linux-g++_src.tar.gz

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	A command line tool for online payment

MAKEFILE=	${WRKSRC}/saferpay/Makefile

USE_GMAKE=	yes
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}

post-patch:
	@${SED} -i orig -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKDIR}/saferpay/Makefile
.if exists(/usr/include/openssl/engine.h)
CFLAGS+=	-DHAVE_SSLENGINE_H
.endif

.if !defined(WITH_P5_API)
pre-build:
	@${ECHO} "-----------------------------------------------------"
	@${ECHO} You are building now the saferpay command line tool.
	@${ECHO} If you like to install the perl API too, break this
	@${ECHO} installation and start it again with WITH_P5_API=YES.
	@${ECHO} "-----------------------------------------------------"
.else
pre-build:
PLIST=		${PKGDIR}/pkg-plist.p5
post-build:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} xs)
post-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} installxs)
	${GZIP_CMD} ${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/../man/man3/soplex::saferpay::MessageObject.3
	${GZIP_CMD} ${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/../man/man3/soplex::saferpay::MessageFactory.3
.endif

.include <bsd.port.mk>
