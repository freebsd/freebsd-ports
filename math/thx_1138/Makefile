# New ports collection makefile for:	thx-1138
# Date created:		14 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	thx_1138
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	${PORTNAME:S,_,-,}_source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Paper for Calculations and Graphs

EXTRACT_DEPENDS=	${NONEXISTENT}:${JXPORT}:configure
BUILD_DEPENDS=	makemake:${JXPORT}
LIB_DEPENDS=	jx-1_5_3.1:${JXPORT} \
		j2dplot-0_6_5.0:${PORTSDIR}/x11-toolkits/libj2dplot \
		jparser-1_1_8.1:${PORTSDIR}/x11-toolkits/libjparser

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
MAKE_ENV=	JX_INSTALL_ROOT="${X11BASE}/bin" \
		JX_LIB_ROOT="${X11BASE}/lib"
PLIST_SUB=	PORTNAME="${PORTNAME:S,_,-,}"

# Make environment
PORTINCLUDES=	-I${X11BASE}/include/jx \
		-I${X11BASE}/include/jcore \
		-I${X11BASE}/include/j2dplot \
		-I${X11BASE}/include/jparser \
		-I${X11BASE}/include

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# program files
PROGRAMFILES=		thx-1138/thx-1138
# documents
DOCFILES=	LICENSE README.binary
DOCDIR_PREFIX=	${PREFIX}/share/doc/${PORTNAME:S,_,-,}
# additional configuration and header files
EXTRALIB_PREFIX=	${X11BASE}/lib/jx
EXTRALIBFILES_MAKE_WRKSRC=	include/make
# main jx distribution files needed for building
COPY_JXDIRS=	include
COPY_JXFILES=	Makefile

.include <bsd.port.pre.mk>

# main jx distribution port wrksrc
JXPORT=		${PORTSDIR}/x11-toolkits/jx
JXPORT_WRKSRC!=	cd ${JXPORT} && ${MAKE} -V WRKSRC
JX_MAKE_CONSTANTS=	j2dplot_constants jparser_constants

.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
.else
ALL_TARGET=	freebsd2.x
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

pre-build:
.for i in ${JX_MAKE_CONSTANTS}
	@${LN} -sf ${EXTRALIB_PREFIX}/make/${i} ${WRKSRC}/include/make
.endfor

post-build:
	@cd ${WRKSRC}/programs/${PORTNAME:S,_,-,}; ${SETENV} ${MAKE_ENV} makemake; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS}

do-install:
.if !defined(NOPORTDOCS)
# Install all documentation
	@${INSTALL_DATA_DIR} ${DOCDIR_PREFIX}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/programs/${PORTNAME:S,_,-,}/${i} ${DOCDIR_PREFIX}
.endfor
.endif # !defined(NOPORTDOCS)
# Install all programs
.for i in ${PROGRAMFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/programs/${i} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
