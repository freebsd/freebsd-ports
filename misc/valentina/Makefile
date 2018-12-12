# $FreeBSD$

PORTNAME=	valentina
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sewing pattern drafting tool aiming to remake the garment industry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL.txt

USES=		compiler:c++11-lang desktop-file-utils gl gmake qmake qt:5
USE_QT=		concurrent core gui network opengl printsupport svg widgets xml xmlpatterns buildtools_build linguisttools_build testlib_build
USE_GL=		gl
USE_LDCONFIG=	yes

BB_ACCOUNT=	dismine
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	a2e2f6648b28

QMAKE_ARGS=	CONFIG+="noTests" CONFIG+="noRunPath"
.if !defined(WITH_CCACHE_BUILD) || defined(NO_CCACHE)
QMAKE_ARGS+=	CONFIG+="no_ccache"
.endif
BINARY_ALIAS=	hg=/usr/bin/true

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

post-patch:
	@${REINPLACE_CMD} 's|DEFAULT_PREFIX = /usr|DEFAULT_PREFIX = ${PREFIX}|' ${WRKSRC}/common.pri
	@${REINPLACE_CMD} 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/src/app/valentina/valentina.pro ${WRKSRC}/src/app/tape/tape.pro
	@${REINPLACE_CMD} 's|g++ -dumpversion|g++${GCC_DEFAULT} -dumpversion|' ${WRKSRC}/Valentina.pro

.include <bsd.port.mk>
