# $FreeBSD$

PORTNAME=	qtchooser
PORTVERSION=	66
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	QT/official_releases/${PORTNAME}
DIST_SUBDIR=	KDE/Qt/qtchooser

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt tool wrapper

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	dual

USES=		gmake tar:xz
DESTDIRNAME=	INSTALL_ROOT
MAKE_ARGS=	prefix=${PREFIX}

SUB_FILES=	update-qtchooser-wrapper
# Keep this synchronized with Uses/qt.mk
SUB_LIST=	QT_SUPPORTED="5"

# bin/linguist -- the second bunch no longer exists in the ports tree
CONFLICTS_INSTALL=	rubygem-github-linguist
CONFLICTS_INSTALL+=	rubygem-github-linguist47 rubygem-gitlab-linguist

QT_QTCHOOSERDIR=${PREFIX}/etc/xdg/qtchooser

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/xdg,${LOCALBASE}/etc/xdg,' \
		${WRKSRC}/src/${PORTNAME}/main.cpp

post-install:
# Install qtchooser config file. Note this is not optimal.
# -> we could install the qtchooser config files via devel/qt5-qmake.
#    Unfortunately they will be missing for ports that only use say "rcc"
#    without qmake.
# So it is easier to install the config files in qtchooser.
# -> As we cannot include Uses/qt.mk at the moment without specifying
#    a version, we also do not have the variables needed to sub the variables
#    properly (we could use USES=qt:5 just to get _QT_SUPPORTED, but that
#    is a lot of overkill).
#
# Always make sure the following is in sync with Uses/qt.mk .
# At the very least all the _QT_SUPPORTED versions should be
# in the .for loop, although we still keep Qt4 around over a year
# after it was removed from the ports tree.
#
	${MKDIR} ${STAGEDIR}${QT_QTCHOOSERDIR}
.for qt_version in 4 5
	${ECHO} ${PREFIX}/lib/qt${qt_version}/bin > ${STAGEDIR}${QT_QTCHOOSERDIR}/qt${qt_version}.conf
	${ECHO} ${PREFIX}/lib/qt${qt_version} >> ${STAGEDIR}${QT_QTCHOOSERDIR}/qt${qt_version}.conf
.endfor
# Install man page.
	${INSTALL_DATA} ${WRKSRC}/doc/qtchooser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
# Create the default profile.
	cd ${STAGEDIR}/${QT_QTCHOOSERDIR} && ${LN} -s qt5.conf default.conf
	${INSTALL_SCRIPT} ${WRKDIR}/update-qtchooser-wrapper \
		${STAGEDIR}${PREFIX}/bin/update-qtchooser-wrapper


.include <bsd.port.mk>
