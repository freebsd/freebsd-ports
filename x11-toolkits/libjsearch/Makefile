# New ports collection makefile for:	libjsearch
# Date created:				04 Jun 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	libjsearch
PORTVERSION=	0.5.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.newplanetsoftware.com/pub/jx/source-1.5.3/ \
		ftp://ftp.newplanetsoftware.com/pub/jcc/source/ \
		ftp://ftp.newplanetsoftware.com/pub/medic/source/ \
		ftp://ftp.cs.itu.edu.tr/pub/linux/x11/jx/
DISTNAME=	JSearch_source-${PORTVERSION}

MAINTAINER=	lioux@linf.unb.br

BUILD_DEPENDS=	nonexistent:${JXPORT}:patch
LIB_DEPENDS=	jx-1_5_3.1:${JXPORT}

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_XLIB=	yes
INSTALLS_SHLIBS=	yes
USE_GMAKE=	yes
MAKE_ENV=	JX_INSTALL_ROOT="${PREFIX}/bin" \
		JX_LIB_ROOT="${PREFIX}/lib" \
		X11PREFIX="${X11PREFIX}" \
		PORTCFLAGS="${CFLAGS}" \
		PORTCXXFLAGS="${CXXFLAGS}" \
		PORTINCLUDES="${PORTINCLUDES}"
PLIST_SUB=	PORTNAME="${PORTNAME}" \
		LIBNUMBER="${LIBNUMBER}" \
		LIBVERSION="${LIBVERSION}" \
		EXTRALIBFILES_MAKE_FILES="${EXTRALIBFILES_MAKE_FILES}" \
		INCLUDEDIR="${INCLUDEDIR}"

# Proper X11R6 Prefix
# Change it, if you need it
X11PREFIX?=	${X11BASE}

# Make environment
PORTINCLUDES=	-I${LOCALBASE}/include/jx -I${LOCALBASE}/share/jx

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# New version number
LIBVERSION=	0_5_6
# the libraries
LIBFILES=	${PORTNAME}-${LIBVERSION}.a ${PORTNAME}-${LIBVERSION}.so
# header files
INCLUDEDIR=	jsearch
# documentation
DOCDIR_PREFIX=	${PREFIX}/share/doc/JX
DOCDIRS=	${PORTNAME}
DOCDIRFILES=	LICENSE
# xpm images
ICONDIRS=	libjsearch/code
ICONDIR_PREFIX=	${PREFIX}/share/jx/jsearch
# additional configuration and header files
EXTRALIB_PREFIX=		${PREFIX}/lib/jx
EXTRALIBDIRS=			lib make
EXTRALIBFILES_MAKE_WRKSRC=	include/make
EXTRALIBFILES_MAKE_FILES=	jsearch_constants
# main jx distribution port wrksrc
JXPORT=		${PORTSDIR}/x11-toolkits/jx
JXPORT_WRKSRC=	${JXPORT}/work/JX-1.5.3
# main jx distribution files needed for building
COPY_JXDIRS=	include lib libjcore
COPY_JXFILES=	Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
LIBNUMBER=	0
.else
ALL_TARGET=	freebsd2.x
LIBNUMBER=	0.5
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS:="@comment "
.else
PLIST_SUB+=	PORTDOCS:=
.endif # !defined(NOPORTDOCS)

post-extract:
.for i in ${COPY_JXDIRS}
	@${CP} -Rp ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor
.for i in ${COPY_JXFILES}
	@${CP} -p ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor

post-build:
	@cd ${WRKSRC}/${PORTNAME}; ${SETENV} ${MAKE_ENV} makemake; \
		${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
.if !defined(NOPORTDOCS)
# Install all documentation
.for i in ${DOCDIRS}
	@for j in ${DOCDIRFILES} ; \
	do \
		if [ -f ${WRKSRC}/programs/${i}/$${j} ]; \
		then \
			${INSTALL_DATA} ${WRKSRC}/programs/${i}/$${j} \
				${DOCDIR_PREFIX}/$${j}_${i} ; \
		elif [ -f ${WRKSRC}/${i}/$${j} ]; \
		then \
			${INSTALL_DATA} ${WRKSRC}/${i}/$${j} \
				${DOCDIR_PREFIX}/$${j}_${i} ; \
		fi ; \
	done
.endfor
.endif # !defined(NOPORTDOCS)
# Install all icons
.for i in ${ICONDIRS}
	@${INSTALL_DATA_DIR} ${ICONDIR_PREFIX} ; \
	for j in ${WRKSRC}/${i}/*.xpm ; \
	do \
		${INSTALL_DATA} $${j} ${ICONDIR_PREFIX} ; \
	done
.endfor
# Install all header files
.for i in ${INCLUDEDIR}
	@${INSTALL_DATA_DIR} ${PREFIX}/include/${i} ; \
	for j in ${WRKSRC}/include/${i}/*.h ; \
	do \
		${INSTALL_DATA} $${j} ${PREFIX}/include/${i} ; \
	done
.endfor
# Install all libraries
.for i in ${LIBFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/lib/${i} ${PREFIX}/lib
.endfor
# Install additional library files
.for i in ${EXTRALIBDIRS}
	@${INSTALL_DATA_DIR} ${EXTRALIB_PREFIX}/${i}
.endfor
.for i in ${EXTRALIBFILES_MAKE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${EXTRALIBFILES_MAKE_WRKSRC}/${i} \
		${EXTRALIB_PREFIX}/make/${i}
.endfor

post-install:
	@${LN} -sf ${PORTNAME}-${LIBVERSION}.so \
		${PREFIX}/lib/${PORTNAME}-${LIBVERSION}.so.${LIBNUMBER}
.for i in ${LIBFILES}
	@${LN} -sf ../../${i} ${EXTRALIB_PREFIX}/lib/${i}
.endfor

.include <bsd.port.post.mk>
