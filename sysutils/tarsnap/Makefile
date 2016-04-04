# Created by: Colin Percival
# $FreeBSD$

PORTNAME=	tarsnap
PORTVERSION=	1.0.37
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tarsnap.com/download-http/
DISTNAME=	${PORTNAME}-autoconf-${PORTVERSION}

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Online encrypted backup service (client)

GNU_CONFIGURE=	yes
USES=		gmake tar:tgz

.include <bsd.port.pre.mk>

# safety check to ensure that we don't violate the license
.if exists(${PATCHDIR})
RESTRICTED=	license only allows redistribution and use of unmodified source and binaries
.endif
LEGAL_TEXT=	license restricts redistribution of source and binaries

.include <bsd.port.post.mk>
