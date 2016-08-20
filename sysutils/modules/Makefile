# Created by: Hokan
# $FreeBSD$

PORTNAME=	modules
PORTVERSION=	3.2.10
PORTREVISION=	1
CATEGORIES=	sysutils tcl
MASTER_SITES=	SF/${PORTNAME}/Modules/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic modification of a user environment

LICENSE=	GPLv2

USES=		tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x \
		--with-version-path=${PREFIX}/Modules/versions \
		--mandir=${MANPREFIX}/man \
		--with-tcl-ver=${TCL_VER:S/.//} \
		--with-tcl-inc=${TCL_INCLUDEDIR} \
		--with-tcl-lib=${LOCALBASE}/lib \
		--with-tclx-ver=${TCL_VER:S/.//}

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

post-extract:
	${MV} ${WRKSRC}/doc/modulefile.4.in ${WRKSRC}/doc/modulefile.5.in

.include <bsd.port.mk>
