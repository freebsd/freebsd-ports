# Created by: Marie Loise Nolden <nolden@kde.org>
# $FreeBSD$

PORTNAME=	doc
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/online/qtsdkrepository/linux_x64/desktop/qt5_${QT5_VERSION:S/.//g}_src_doc_examples/qt.${QT5_VERSION:S/.//g}.doc/
PKGNAMEPREFIX=	qt5-
DISTNAME=	${QT5_VERSION}-0-201711211135qt-everywhere-documentation
DIST_SUBDIR=	KDE/Qt/${QT5_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 documentation

WRKSRC=		${WRKDIR}/Docs/Qt-${QT5_VERSION}

# bsdtar(1) from 10.3 and earlier cannot read the distfile correctly:
#   tar: Damaged 7-Zip archive
# Depend on p7zip across all versions because Uses/7z.mk does not work if
# included after bsd.port.pre.mk.
USES=		7z:p7zip
USE_QT5=	# we just need access to QT5_VERSION and other variables.

DESCR=		${.CURDIR:H:H}/devel/qt5/pkg-descr
NO_ARCH=	yes
NO_BUILD=	yes

post-extract:
	${RM} ${WRKSRC}/Makefile
	${RM} -r ${WRKSRC}/global

do-install:
	${MKDIR} ${STAGEDIR}${QT_DOCDIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${QT_DOCDIR}

.include <bsd.port.mk>
