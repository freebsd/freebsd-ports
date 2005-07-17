# New ports collection makefile for:	pkg_trackinst
# Date created:		3 May 2005
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pkg_trackinst
PORTVERSION=	1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~perky/distfiles/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	PkgDB/pkg-plist generator by tracking installation

USE_PYTHON=	2.3+
USE_REINPLACE=	yes
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501105
IGNORE=		requires dynamically-linked base programs
.endif

post-patch:
	${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/PkgTrackInst/cmd_support.py

.include <bsd.port.post.mk>
