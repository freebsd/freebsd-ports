# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	tclgpg
PORTVERSION=	0.0.0.20150324
CATEGORIES=	security tcl
MASTER_SITES=	http://chiselapp.com/user/sgolovan/repository/tclgpg/tarball/
DISTNAME=	tclgpg-4cfd9fa949

MAINTAINER=	mp39590@gmail.com
COMMENT=	Tcl interface to GNU Privacy Guard with interface similar to TclGPGME

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	dtplite:devel/tcllib
RUN_DEPENDS=	gpg:security/gnupg1

USES=		autoreconf gmake tcl:tea
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/tclgpg-4cfd9fa949

PLIST_FILES=	lib/gpg1.0/libgpg1.0.so \
		lib/gpg1.0/pkgIndex.tcl \
		lib/gpg1.0/tclgpg.tcl \
		man/mann/gpg.n.gz

.include <bsd.port.mk>
