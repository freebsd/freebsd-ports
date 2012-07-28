# ex:ts=8
# Ports collection makefile for:	tdhkit
# Date created:			2 Mar 2010
# Whom:				corky1951@comcast.net
#
# $FreeBSD$
#

PORTNAME=	tdhkit
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://quisp.sourceforge.net/${PORTNAME}/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//1}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of programs for working with tabular ASCII data

OPTIONS=	LIBCHRON "Install libchron" Off

.include <bsd.port.options.mk>

.if defined(WITH_LIBCHRON)
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

.if defined(WITH_LIBCHRON)
MAN3=		libchron.3
.endif
MANCOMPRESSED=	no
.endif

do-build:
	cd ${WRKSRC}/libsrc && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
.if defined(WITH_LIBCHRON)
	cd ${WRKSRC}/libsrc && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} libchron
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin

.if defined(WITH_LIBCHRON)
	${INSTALL_PROGRAM} ${WRKSRC}/libchron.a ${PREFIX}/lib
.endif

.if !defined(NO_INSTALL_MANPAGES)
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/mantdh/${manpage} ${MAN1PREFIX}/man/man1
.endfor
.if defined(WITH_LIBCHRON)
	${INSTALL_MAN} ${WRKSRC}/man/mantdh/${MAN3} ${MAN3PREFIX}/man/man3
.endif
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/man/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
