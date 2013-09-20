# Created by: corky1951@comcast.net
# $FreeBSD$

PORTNAME=	tdhkit
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://quisp.sourceforge.net/${PORTNAME}/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//1}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of programs for working with tabular ASCII data

OPTIONS_DEFINE=	LIBCHRON DOCS
LIBCHRON_DESC=	Install libchron

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBCHRON}
PLIST_SUB+=	LIBCHRON=""
.else
PLIST_SUB+=	LIBCHRON="@comment "
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		dateconvert.1 \
		fldfmt.1 \
		fldmap.1 \
		fldsel.1 \
		pjoin.1 \
		recsel.1 \
		tabo.1 \
		tdhfunction.1 \
		xlcells.1 \
		xlcleaner.1

.if ${PORT_OPTIONS:MLIBCHRON}
MAN3=		libchron.3
.endif
MANCOMPRESSED=	no
.endif

do-build:
	cd ${WRKSRC}/libsrc && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
.if ${PORT_OPTIONS:MLIBCHRON}
	cd ${WRKSRC}/libsrc && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} libchron
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin

.if ${PORT_OPTIONS:MLIBCHRON}
	${INSTALL_PROGRAM} ${WRKSRC}/libchron.a ${PREFIX}/lib
.endif

.if !defined(NO_INSTALL_MANPAGES)
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/mantdh/${manpage} ${MAN1PREFIX}/man/man1
.endfor
.if ${PORT_OPTIONS:MLIBCHRON}
	${INSTALL_MAN} ${WRKSRC}/man/mantdh/${MAN3} ${MAN3PREFIX}/man/man3
.endif
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/man/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
