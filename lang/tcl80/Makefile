# New ports collection makefile for:	tcl8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tcl
PORTVERSION=	8.0.5
PORTREVISION=	3
CATEGORIES=	lang tcl80
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=tcl8_0
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tool Command Language

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/tcl8.0.5/unix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

SHLIB_MAJOR=	1
SHLIB_MINOR=	5
MAKEFILE=	makefile
TCL_LIB=	libtcl80.so

OPTIONS=	TCL80_MAN "Install tcl 8.0 manpages" off

.include <bsd.port.pre.mk>

.if !defined(NO_INSTALL_MANPAGES) && defined(WITH_TCL80_MAN)
.include "${FILESDIR}/manpages"
MANCOMPRESSED=	yes
.endif

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
	   OSVERSION=${OSVERSION}

post-install:
.if !defined(NO_INSTALL_MANPAGES) && defined(WITH_TCL80_MAN)
	@cd ${WRKSRC} && ${MAKE} -f Makefile install-man
.endif
	${LN} -sf ${TCL_LIB}.${SHLIB_MAJOR} ${PREFIX}/lib/${TCL_LIB}

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
