# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkg_trackinst
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://people.freebsd.org/~perky/distfiles/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	PkgDB/pkg-plist generator by tracking installation

USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/PkgTrackInst/cmd_support.py

.include <bsd.port.mk>
