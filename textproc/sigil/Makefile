# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	sigil
PORTVERSION=	0.6.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	Sigil-${PORTVERSION}-Code

MAINTAINER=	jonc@chen.org.nz
COMMENT=	WYSIWYG ePub editor

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libpcre.so:${PORTSDIR}/devel/pcre

USES=		cmake compiler desktop-file-utils pkgconfig zip
NO_WRKSUBDIR=	yes
USE_QT4=	qmake gui svg webkit xml moc uic rcc imageformats linguist

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/CMakeLists.txt
.if ${COMPILER_TYPE} == gcc
# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
	@${REINPLACE_CMD} -e '/precompiled_header/d' \
		${WRKSRC}/src/FlightCrew/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
