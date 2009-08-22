# New ports collection makefile for:	rox-session
# Date created:        11 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox-session
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/rox/ROX-Session/${PORTVERSION}
DISTNAME=	rox-session-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A session manager for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_BZIP2=	yes
USE_PYTHON=	yes

SUB_FILES=	rox-session rox.desktop

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/sbin/gdm)
WITH_GDM=	yes
.endif

.if defined(WITH_GDM)
RUN_DEPENDS+=	${LOCALBASE}/sbin/gdm:${PORTSDIR}/x11/gdm
PLIST_SUB+=	GDM=""
.else
PLIST_SUB+=	GDM="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name *.orig | ${XARGS} ${RM}

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/ROX-Session ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/ROX-Session
	@${INSTALL_SCRIPT} ${WRKDIR}/rox-session ${PREFIX}/sbin
.if defined(WITH_GDM)
	@${INSTALL_DATA} ${WRKDIR}/rox.desktop ${PREFIX}/etc/dm/Sessions
.endif

.include <bsd.port.post.mk>
