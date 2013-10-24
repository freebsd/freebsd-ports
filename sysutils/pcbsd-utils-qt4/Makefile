# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils-qt4
PORTVERSION=	1382605460
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD QT4 Utilities

RUN_DEPENDS=	pc-metapkgmanager:${PORTSDIR}/sysutils/pcbsd-utils
LIB_DEPENDS=	QtSolutions_SingleApplication-head.1:${PORTSDIR}/devel/qt4-qtsolutions-singleapplication \
		curl:${PORTSDIR}/ftp/curl

MAKE_JOBS_UNSAFE=yes
USE_CDRTOOLS=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_QT4=	accessible \
		clucene codecs-cn codecs-jp codecs-kr codecs-tw corelib \
		dbus declarative \
		graphicssystems-opengl gui help help-tools \
		iconengines imageformats inputmethods \
		linguist l10n makeqpf moc multimedia network opengl \
		pixeltool porting phonon phonon-gst \
		qdbusviewer qmlviewer qmake qtconfig qtestlib \
		qvfb rcc script scripttools \
		svg uic uic3 \
		xml xmlpatterns xmlpatterns-tool

WRKSRC=		${WRKDIR}/src-qt4
HAS_CONFIGURE=	yes

QMAKE_PRO=	src-qt4.pro
QMAKE_ARGS=	-recursive ${QMAKE_PRO}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900030
IGNORE=		requires FreeBSD 9.0 or later
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} -unix CONFIG+="configure" ${QMAKE_PRO}

do-install:
	cd ${WRKSRC} && make install INSTALL_ROOT=${STAGEDIR}

.include <bsd.port.post.mk>
