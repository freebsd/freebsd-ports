# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mod_extract_forwarded
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.openinfo.co.uk/apache/
DISTNAME=	extract_forwarded-${DISTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	An Apache module that can make proxied requests appear with client IP

OPTIONS_DEFINE=	YOSHFUJI
YOSHFUJI_DESC=	yoshfuji patch (support IPv6 addr in config, etc)
#OPTIONS_DEFAULT=	YOSHFUJI

USE_APACHE=	22
WRKSRC=		${WRKDIR}/extract_forwarded
PORTDOCS=	INSTALL README
MAKE_JOBS_SAFE=	yes
PATCH_STRIP=	-p1

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

# Workaround for UNIQUENAME v.s. OptionsNG problem.
#   http://lists.freebsd.org/pipermail/freebsd-ports/2012-June/075466.html
UNIQUENAME=	ap22-${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MYOSHFUJI}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-yoshfuji
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-mod_extract_forwarded.c
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
