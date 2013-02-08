# Created by: lbartoletti <coer@tuxfamily.org>
# $FreeBSD$

PORTNAME=	scribus
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	print editors
MASTER_SITES=	http://download.tuxfamily.org/bartcoding/FreeBSD/ \
				${MASTER_SITE_LOCAL}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SVN_REV}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		cups:${PORTSDIR}/print/cups-base \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		podofo:${PORTSDIR}/graphics/podofo \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		aspell:${PORTSDIR}/textproc/aspell \
		cairo:${PORTSDIR}/graphics/cairo \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		incorrect plist

USE_SVN=	yes
USE_BZIP2=	yes
USE_QT4=	gui linguist_build moc_build qmake_build rcc_build uic_build xml network
USE_GNOME=	desktopfileutils libartlgpl2 libxml2 pkgconfig
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

MAN1=		scribus.1
MANLANG=	"" de pl
MANCOMPRESSED=	no

FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	17518		# svn tip at epoch 2009120801
SVNROOT_URI=	svn://scribus.net/trunk/Scribus

.include <bsd.port.pre.mk>

post-install:
	${LN} ${DATADIR}/icons/scribus.png ${PREFIX}/share/pixmaps/
	-update-desktop-database
	-update-mime-database ${PREFIX}/share/mime
#
# To roll snapshot: as bart (or other maintainer) : make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI} ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bart
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.bz2
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif # defined(BOOTSTRAP)

.include <bsd.port.post.mk>
