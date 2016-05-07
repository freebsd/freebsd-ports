# Created by: Hokan
# $FreeBSD$

PORTNAME=	modules
PORTVERSION=	3.2.10
CATEGORIES=	sysutils tcl
MASTER_SITES=	SF/${PORTNAME}/Modules/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic modification of a user environment

LICENSE=	GPLv2

LIB_DEPENDS=	libtcl84.so:lang/tcl84

TCL_DVER?=	8.4
TCL_VER=	${TCL_DVER:S/.//}
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--without-x \
		--with-version-path=${LOCALBASE}/Modules/versions \
		--mandir=${MANPREFIX}/man \
		--with-tcl-ver=${TCL_VER} \
		--with-tcl-inc=${LOCALBASE}/include/tcl${TCL_DVER} \
		--with-tcl-lib=${LOCALBASE}/lib \
		--with-tclx-ver=${TCL_VER}

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

post-extract:
	${MV} ${WRKSRC}/doc/modulefile.4.in ${WRKSRC}/doc/modulefile.5.in

.include <bsd.port.mk>
