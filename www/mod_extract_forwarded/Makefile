# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mod_extract_forwarded
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.openinfo.co.uk/apache/
DISTNAME=	extract_forwarded-${DISTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Apache module that can make proxied requests appear with client IP

OPTIONS_DEFINE=	YOSHFUJI
YOSHFUJI_DESC=	yoshfuji patch (support IPv6 addr in config, etc)
#OPTIONS_DEFAULT=	YOSHFUJI

USES=		apache:2.2
WRKSRC=		${WRKDIR}/extract_forwarded
PORTDOCS=	INSTALL README
PATCH_STRIP=	-p1

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MYOSHFUJI}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-yoshfuji
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-mod_extract_forwarded.c
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
