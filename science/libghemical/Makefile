# New ports collection makefile for: libghemical
# Date created:			July 3, 2006
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	2.98
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/release20080731/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	openbabel:${PORTSDIR}/science/openbabel \
		mopac7:${PORTSDIR}/biology/mopac
LIB_DEPENDS+=	mpqc:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes

.include <bsd.port.pre.mk>

USE_FORTRAN=	yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ARGS+=	--enable-mpqc --enable-openbabel --enable-mopac7 

PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

.if ${OSVERSION} >= 700000
BROKEN=		does not configure
.endif

.include <bsd.port.post.mk>
