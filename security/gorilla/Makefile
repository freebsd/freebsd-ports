# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	gorilla
PORTVERSION=	1.5.3.6
DISTVERSIONSUFFIX=	a72f9d7
CATEGORIES=	security
MASTER_SITES=	LOCAL/crees/gorilla/				\
		http://www.bayofrum.net/dist/${PORTNAME}/
DISTFILES=	zdia-${PORTNAME}-v${DISTVERSION}-0-g${DISTVERSIONSUFFIX}${EXTRACT_SUFX}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Password Gorilla is a cross-platform Password Manager

LICENSE=	GPLv2

RUN_DEPENDS=	itcl>=3.4:lang/itcl \
		wish:x11-toolkits/tk-wrapper

.include <bsd.port.options.mk>

.if ${ARCH} == i386
GORILLAARCH=	FreeBSD-x86
DISTFILES+=	gorilla-sha256-${DISTVERSION}_1${EXTRACT_SUFX}
.elif ${ARCH} == amd64
GORILLAARCH=	FreeBSD-${ARCH}
DISTFILES+=	gorilla-sha256-${DISTVERSION}_1${EXTRACT_SUFX}
.else
GORILLAARCH=	bogus
WITHOUTSO=	"@comment "
.endif

PLIST_SUB+=	GORILLAARCH=${GORILLAARCH:tl} WITHOUTSO=${WITHOUTSO}

WRKSRC=		${WRKDIR}/zdia-${PORTNAME}-${DISTVERSIONSUFFIX}
USES=		tk:85+,run
SUB_FILES=	gorilla
SUB_LIST=	WISH=${WISH}
PORTDOCS=	*

SRC_DIRS=	blowfish modules msgs pics pwsafe tcllib twofish

post-patch:
# We don't want Linux/Windows/Darwin binaries thank you
.for irrelevant in linux-ix86 linux-x86_64 macosx-ix86 \
		   macosx-x86_64 win32-ix86 win32-x86_64
	${RM} -r ${WRKSRC}/sources/tcllib/sha256c/${irrelevant}
.endfor
.for irrelevant in f32-Darwin-x86.dylib f32-Windows-x86.dll \
		   f32-Linux-x86.so f32-Linux-x86_64.so
	${RM} ${WRKSRC}/sources/twofish/${irrelevant}
.endfor

do-build:
.if !defined(WITHOUTSO)
	${MV} ${WRKDIR}/${PORTNAME}-sha256/sha256/${GORILLAARCH}/ \
		${WRKSRC}/sources/tcllib/sha256c/${GORILLAARCH:tl}
.endif


do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gorilla
	@${INSTALL_SCRIPT} ${WRKSRC}/sources/*.tcl \
		${STAGEDIR}${PREFIX}/lib/gorilla
.for dir in ${SRC_DIRS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${dir}
	@cd ${WRKSRC}/sources/${dir} \
		&& ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${dir}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README			\
		${WRKSRC}/sources/README.install-from-source	\
		${WRKSRC}/sources/CHANGES.txt			\
	   ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
