PORTNAME=	valentina
DISTVERSION=	1.0.3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sewing pattern drafting tool aiming to remake the garment industry
WWW=		https://smart-pattern.com.ua/en/ \
		https://gitlab.com/smart-pattern/valentina

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL.txt

BUILD_DEPENDS=	qbs:devel/qbs

LIB_DEPENDS=	libxerces-c-3.3.so:textproc/xerces-c3

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl gmake qt:6
USE_QT=		base tools:build svg
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	smart-pattern
GL_TAGNAME=	4d63d4c194f1f3bc0ed5a6f3dce7c955365b6599

DOS2UNIX_FILES=	src/libs/vgeometry/vellipticalarc.cpp

BINARY_ALIAS=	hg=/usr/bin/true git=/usr/bin/false

.include <bsd.port.options.mk>

.if ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc
LLD_UNSAFE=	yes
.endif

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} qbs build -f ${PORTNAME}.qbs --no-install \
		qbs.installPrefix:${PREFIX} \
		moduleProviders.Qt.qmakeFilePaths:${LOCALBASE}/bin/qmake6

do-install:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} qbs install -f ${PORTNAME}.qbs \
		qbs.installPrefix:${PREFIX} \
		moduleProviders.Qt.qmakeFilePaths:${LOCALBASE}/bin/qmake6 && \
		${CP} -r ${WRKSRC}/default/install-root/usr/local/* ${STAGEDIR}${PREFIX}/

.include <bsd.port.mk>
