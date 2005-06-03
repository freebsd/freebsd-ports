# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.11.8
PORTREVISION=	3
CATEGORIES=	palm comms
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PalmPilot communications utilities (backup/restore/install/debug/...)

USE_ICONV=	yes
USE_GETOPT_LONG=yes
USE_BZIP2=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_PERL5=	yes
TCL_VER?=	8.4

CFLAGS+=	-I${LOCALBASE}/include
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl5=${PERL5} --with-libiconv=${LOCALBASE} --program-transform-name=
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	TCL "Build Tcl/Tk bindings" off

.include "${.CURDIR}/manpages.mk"
.include <bsd.port.pre.mk>

.if defined(WITH_TCL)
LIB_DEPENDS+=	tk${TCL_VER:S/.//}:${PORTSDIR}/x11-toolkits/tk${TCL_VER:S/.//}
CONFIGURE_ARGS+=--with-tclinclude=${LOCALBASE}/include/tcl${TCL_VER}/ --with-tcl=${LOCALBASE}/lib/tcl${TCL_VER}/
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

.include <bsd.port.post.mk>
