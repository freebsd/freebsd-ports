# New ports collection makefile for:	itk
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itk
PORTVERSION=	3.0.1
CATEGORIES=	x11-toolkits tk82
MASTER_SITES=	ftp://ftp.tcltk.com/pub/itcl/
DISTNAME=	itcl${PORTVERSION}

MAINTAINER=	dmlb@ragnet.demon.co.uk

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		itcl30.1:${PORTSDIR}/lang/itcl

WRKSRC=		${WRKDIR}/itcl3.0.1/itk/unix
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl8.2 --with-itcl=${PREFIX}/lib/itcl3.0 --with-tk=${PREFIX}/lib/tk8.2
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} ITK_LIB_FILE=${ITK_LIB_FILE}

SHLIB_MAJOR=	1
SHLIB_MINOR=	1
MAKEFILE=	makefile
ITK_LIB=	libitk30.so

MANCOMPRESSED=	yes
MAN1=		itkwish.1
MANN=		Archetype.n Toplevel.n Widget.n itk.n itkvars.n usual.n

.include <bsd.port.pre.mk>

ITK_LIB_FILE=	${ITK_LIB}.${SHLIB_MAJOR}

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
	   TCL_PREFIX=${PREFIX} ITCL_PREFIX=${PREFIX} TK_PREFIX=${PREFIX}

post-install:
	${LN} -sf itkwish3.0 ${PREFIX}/bin/itkwish
	${LN} -sf ${ITK_LIB_FILE} ${PREFIX}/lib/${ITK_LIB}

.include <bsd.port.post.mk>
