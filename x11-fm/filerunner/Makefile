PORTNAME=	filerunner
DISTVERSION=	26.09.03.12
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/release-${DISTVERSION}
DISTNAME=	fr-${DISTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Tcl/Tk-based filemanager with FTP capabilities
WWW=		https://sourceforge.net/projects/filerunner/

LICENSE=	GPLv3

USES=		desktop-file-utils python:run shebangfix tk:run

SHEBANG_FILES=	fr fr.tcl frftp frlib/snitIndex.tcl Makefiles/INSTALL
SHEBANG_LANG=	tclsh wish
tclsh_CMD=	${TCLSH}
wish_CMD=	${WISH}

EXTRACT_AFTER_ARGS=	--exclude inotify --exclude trim-inotify.tcl
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDATA=	*

post-patch:
	${REINPLACE_CMD} -e \
		'/python3/s,execok python3,execok ${PYTHON_VERSION},' \
		 ${WRKSRC}/packages/expect/expect.tcl

do-install:
	cd ${WRKSRC}/Makefiles && ${SETENV} DESTDIR=${STAGEDIR} \
		prefix=${PREFIX}/share GCONFIG=${PREFIX}/etc \
		EXEC=${PREFIX}/bin ./INSTALL --verbose

.include <bsd.port.mk>
