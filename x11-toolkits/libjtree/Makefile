# New ports collection makefile for:	libjtree
# Date created:				30 May 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	libjtree
PORTVERSION=	1.1.7
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.krasnodar.ru/pub/unix/IDE/CodeCrusader/ \
		ftp://ftp.uniovi.es/pub/unix/mail/
DISTNAME=	JTree_source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An additional library for the JX widget library

EXTRACT_DEPENDS=	${NONEXISTENT}:${JXPORT}:configure
BUILD_DEPENDS=	makemake:${JXPORT}
LIB_DEPENDS=	jx-1_5_3.1:${JXPORT}

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
MAKE_ENV=	JX_INSTALL_ROOT="${PREFIX}/bin" \
		JX_LIB_ROOT="${PREFIX}/lib"
PLIST_SUB=	PORTNAME="${PORTNAME}" \
		LIBNUMBER="${LIBNUMBER}" \
		LIBVERSION="${LIBVERSION}" \
		EXTRALIBFILES_MAKE_FILES="${EXTRALIBFILES_MAKE_FILES}" \
		INCLUDEDIR="${INCLUDEDIR}"
INSTALLS_SHLIB=	yes

# Make environment
PORTINCLUDES=	-I${X11BASE}/include/jx -I${X11BASE}/include/jcore

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# New version number
LIBVERSION=	1_1_7
# the libraries
LIBFILES=	${PORTNAME}-${LIBVERSION}.a ${PORTNAME}-${LIBVERSION}.so
# header files
INCLUDEDIR=	jtree
# documentation
DOCDIR_PREFIX=	${PREFIX}/share/doc/jx
DOCDIRS=	${PORTNAME}
DOCDIRFILES=	LICENSE
# additional configuration and header files
EXTRALIB_PREFIX=		${PREFIX}/lib/jx
EXTRALIBDIRS=			lib make
EXTRALIBFILES_MAKE_WRKSRC=	include/make
EXTRALIBFILES_MAKE_FILES=	jtree_constants

.include <bsd.port.pre.mk>

# main jx distribution port wrksrc
JXPORT=		${PORTSDIR}/x11-toolkits/jx
JXPORT_WRKSRC!=	cd ${JXPORT} && ${MAKE} -V WRKSRC
# main jx distribution files needed for building
COPY_JXDIRS=	include
COPY_JXFILES=	Makefile

.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
LIBNUMBER=	1
.else
ALL_TARGET=	freebsd2.x
LIBNUMBER=	1.1
.endif

post-extract:
.for i in ${COPY_JXDIRS}
	@${CP} -Rp ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor
.for i in ${COPY_JXFILES}
	@${CP} -p ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor

post-patch:
	@${ECHO_CMD} "SEARCHDIRS += ${PORTINCLUDES}" >> \
		${WRKSRC}/${EXTRALIBFILES_MAKE_WRKSRC}/jx_constants

post-build:
	@cd ${WRKSRC}/${PORTNAME}; ${SETENV} ${MAKE_ENV} makemake; \
		${SETENV} ${MAKE_ENV} ${GMAKE} \
			${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

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
