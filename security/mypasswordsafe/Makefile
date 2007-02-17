# New ports collection makefile for:	mypasswordsafe
# Date created:				2006-11-26
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	MyPasswordSafe
PORTVERSION=	20061216
CATEGORIES=	security
MASTER_SITES=	http://www.semanticgap.com/myps/release/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Easy-to-use password manager compatible with Password Safe

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GMAKE=	yes
USE_KDELIBS_VER=3
MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"

post-patch:
	@${REINPLACE_CMD} -Ee 's|(USER=)\$$\(USER\)|\1$$(shell whoami)|' \
		${WRKSRC}/${MAKEFILE}
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '63,64d; 66,67d' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.mk>
