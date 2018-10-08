# $FreeBSD$

PORTNAME=	qtchooser
PORTVERSION=	66
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

# bin/linguist
CONFLICTS_INSTALL=	rubygem-github-linguist rubygem-github-linguist47 rubygem-gitlab-linguist

QT_QTCHOOSERDIR=${PREFIX}/etc/xdg/qtchooser

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/xdg,${LOCALBASE}/etc/xdg,' \
		${WRKSRC}/src/${PORTNAME}/main.cpp

post-install:
# Install qtchooser config file. Note this is not optimal.
# -> we could install the qtchooser config files via devel/qmake[45].
#    Unfortunately they will be missing for ports that only use say "rcc"
#    without qmake.
# So it is easier to install the config files in qtchooser.
# -> As we cannot include bsd.qt.mk at the moment without specifying
#    a version, we also do not have the variables needed to sub the variables
#    properly (this will probably change with qt.mk).
# Always make sure the following is in sync with bsd.qt.mk for now.
	${MKDIR} ${STAGEDIR}${QT_QTCHOOSERDIR}
.for qt_version in 4 5
	${ECHO} ${PREFIX}/lib/qt${qt_version}/bin > ${STAGEDIR}${QT_QTCHOOSERDIR}/qt${qt_version}.conf
	${ECHO} ${PREFIX}/lib/qt${qt_version} >> ${STAGEDIR}${QT_QTCHOOSERDIR}/qt${qt_version}.conf
.endfor
# Install man page.
	${INSTALL_DATA} ${WRKSRC}/doc/qtchooser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
# Create the default profile.
	cd ${STAGEDIR}/${QT_QTCHOOSERDIR} && ${LN} -s qt5.conf default.conf

.include <bsd.port.mk>
