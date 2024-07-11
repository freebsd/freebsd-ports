PORTNAME=	ini_file_manager
PORTVERSION=	11
CATEGORIES=	misc
MASTER_SITES=	SF/ini-files/ini-files
DISTNAME=	ini-files-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ini configuration file reader and manipulator package for Ada
WWW=		https://sourceforge.net/projects/ini-files/

LICENSE=	MIT

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild
USES=		ada zip dos2unix

_GPR_ARGS=      -j${MAKE_JOBS_NUMBER} -p

WRKSRC=		${WRKDIR}/ini-files

post-extract:
	${CP} ${FILESDIR}/construct.gpr ${WRKSRC}
	${MKDIR} ${WRKSRC}/src
	${MV} ${WRKSRC}/config.ad[bs] ${WRKSRC}/src

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gprbuild ${_GPR_ARGS} -P construct

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/ini_file_manager \
		${STAGEDIR}${PREFIX}/include/ini_file_manager
	${INSTALL_DATA} ${FILESDIR}/ini_file_manager.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${STAGEDIR}${PREFIX}/include/ini_file_manager
	${INSTALL_DATA} ${WRKSRC}/lib/*  \
		${STAGEDIR}${PREFIX}/lib/ini_file_manager

.include <bsd.port.mk>
