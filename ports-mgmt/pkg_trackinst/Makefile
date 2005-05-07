# New ports collection makefile for:	pkg_trackinst
# Date created:		3 May 2005
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pkg_trackinst
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~perky/distfiles/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	PkgDB/pkg-plist generator by tracking installation

RUN_DEPENDS=	${LOCALBASE}/lib/installwatch.so:${PORTSDIR}/sysutils/installwatch

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501105
IGNORE=		requires dynamically-linked base programs
.endif

post-patch:
	${REINPLACE_CMD} 's/\(open_manlist_output()\)/self\.\1/g' \
		${WRKSRC}/PkgTrackInst/PlistWriter.py

.include <bsd.port.post.mk>
