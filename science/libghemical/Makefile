# New ports collection makefile for: libghemical
# Date created:			July 3, 2006
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	2.99.1
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/release20090911/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	openbabel:${PORTSDIR}/science/openbabel \
		mopac7:${PORTSDIR}/biology/mopac \
		intltool-update:${PORTSDIR}/textproc/intltool \
		ld:${PORTSDIR}/devel/binutils
LIB_DEPENDS+=	mpqc:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes

USE_FORTRAN=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:22 automake:110
CONFIGURE_ARGS+=	--enable-mpqc
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

pre-build:
	${RM} -f ${WRKSRC}/libtool
	${LN} -sf ${LIBTOOL} ${WRKSRC}/libtool

.include <bsd.port.post.mk>
