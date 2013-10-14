# Created by: lbartoletti <coer@tuxfamily.org>
# $FreeBSD$

PORTNAME=	scribus
PORTVERSION=	1.5.0
PORTREVISION=	5
CATEGORIES=	print editors
MASTER_SITES=	http://download.tuxfamily.org/bartcoding/FreeBSD/ \
				${MASTER_SITE_LOCAL}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SVN_REV}
PKGNAMESUFFIX=	-devel

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Comprehensive desktop publishing program

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
		execinfo:${PORTSDIR}/devel/libexecinfo \
		poppler:${PORTSDIR}/graphics/poppler \
		osg:${PORTSDIR}/graphics/osg
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

CONFLICTS=	scribus-1.[0-4]*

USE_BZIP2=	yes
USE_QT4=	gui linguist_build moc_build qmake_build rcc_build uic_build xml network
USE_GNOME=	desktopfileutils libartlgpl2 libxml2
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USES=		cmake pkgconfig
USE_LDCONFIG=	yes

MAN1=		scribus.1
MANLANG=	"" de pl
MANCOMPRESSED=	no

FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	17820		# svn tip at epoch 2009120801
SVNROOT_URI=	svn://scribus.net/trunk/Scribus

NO_STAGE=	yes
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
