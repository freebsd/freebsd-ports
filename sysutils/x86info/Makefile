# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	x86info
DISTVERSION=	1.31snap01
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	x86 CPU identification and feature display utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpci.so:devel/libpci

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	kernelslacker
GH_PROJECT=	x86info
GH_TAGNAME=	636fbaa

USES=		gmake pkgconfig python:build

PLIST_FILES=	bin/lsmsr bin/x86info man/man8/lsmsr.8.gz man/man1/x86info.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|python createheader.py|${PYTHON_CMD} createheader.py|' \
		${WRKSRC}/lsmsr/Makefile

do-build:
	@cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${WRKSRC}/lsmsr ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x86info ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lsmsr/lsmsr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/x86info.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/lsmsr/lsmsr.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
