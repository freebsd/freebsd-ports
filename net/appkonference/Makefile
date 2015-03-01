# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	appkonference
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Asterisk voice/video conferencing plugin

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_CSTD=	gnu89
USES=		compiler:features gmake
WRKSRC=		${WRKDIR}/${PORTNAME}/konference

PLIST_FILES=	lib/asterisk/modules/app_konference.so

ONLY_FOR_ARCHS=		amd64 arm i386 ia64
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang" && ${COMPILER_VERSION} < 36
post-patch:
	@${REINPLACE_CMD} -e 's|-fsingle-precision-constant||' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
