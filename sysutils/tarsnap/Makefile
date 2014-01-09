# Created by: Colin Percival
# $FreeBSD$

PORTNAME=	tarsnap
PORTVERSION=	1.0.35
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tarsnap.com/download-http/
DISTNAME=	${PORTNAME}-autoconf-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Online encrypted backup service (client)

GNU_CONFIGURE=	yes
USES=		gmake

OPTIONS_DEFINE=	SSE2
SSE2_DESC=	Use SSE2-optimized code

SSE2_CONFIGURE_ENABLE=	sse2
SSE2_CFLAGS=	-msse2

.include <bsd.port.pre.mk>

# safety check to ensure that we don't violate the license
.if exists(${PATCHDIR})
RESTRICTED=     license only allows redistribution and use of unmodified source and binaries
.endif

.include <bsd.port.post.mk>
