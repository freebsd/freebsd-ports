# New ports collection makefile for:	pkg_trackinst
# Date created:		3 May 2005
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pkg_trackinst
PORTVERSION=	1.2.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://people.freebsd.org/~perky/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PkgDB/pkg-plist generator by tracking installation

USE_PYTHON=	2.4+
INSTALLS_EGGINFO=	yes
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}

post-patch:
	${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/PkgTrackInst/cmd_support.py

.include <bsd.port.mk>
