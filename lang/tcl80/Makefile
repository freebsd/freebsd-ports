# New ports collection makefile for:	tcl8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tcl
PORTVERSION=	8.0.5
PORTREVISION=	1
CATEGORIES=	lang tcl80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/
DISTNAME=	tcl8.0.5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool Command Language

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/tcl8.0.5/unix
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}
PKGINSTALL=	${PKGDIR}/pkg-install.tclsh
PKGDEINSTALL=	${PKGDIR}/pkg-deinstall.tclsh

SHLIB_MAJOR=	1
SHLIB_MINOR=	5
MAKEFILE=	makefile
TCL_LIB=	libtcl80.so

.include <bsd.port.pre.mk>

.if defined(WITH_TCL80_MAN)
.include "${FILESDIR}/manpages"
.endif

MANCOMPRESSED=	yes

.if ${PORTOBJFORMAT} == "elf"
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}
.else
TCL_LIB_FILE=	${TCL_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LN} -sf ${TCL_LIB_FILE} ${PREFIX}/lib/${TCL_LIB}
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
