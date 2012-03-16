# New ports collection makefile for:	sigil
# Date created:		2010-09-07
# Whom:			Jonathan Chen <jonc@chen.org.nz>
#
# $FreeBSD$
#

PORTNAME=	sigil
PORTVERSION=	0.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	Sigil-${PORTVERSION}-Code

MAINTAINER=	jonc@chen.org.nz
COMMENT=	WYSIWYG ePub editor

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
		hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		pcre.1:${PORTSDIR}/devel/pcre

USE_ZIP=	yes
USE_CMAKE=	yes
USE_DOS2UNIX=	CMakeLists.txt DirEnumerator.cpp ZipFile_stl.cpp ZipPlatform_lnx.cpp
USE_QT_VER=	4
NO_WRKSUBDIR=	yes
QT_COMPONENTS=	qmake gui svg webkit xml moc uic rcc imageformats linguist

DESKTOP_ENTRIES="Sigil Editor" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/sigil.png" \
		"sigil" \
		"Application;" \
		${FALSE}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.include <bsd.port.post.mk>
