# New ports collection makefile for:	Glide
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Glide3-64Bit
PORTVERSION=	20010331
CATEGORIES=	graphics
MASTER_SITES=	http://www.teleport.com/~anholt/devel/dri/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nsayer
DISTFILES=	${PORTNAME}-20010331.tgz \
		${PORTNAME:S/G/g/}-2001-01-06.tar.gz
EXTRACT_ONLY=	${PORTNAME}-20010331.tgz

PATCH_SITES=	http://www.teleport.com/~anholt/devel/dri/
PATCHFILES=	${PORTNAME:S/G/g/}-2001-01-06.diff

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/Glide3
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
MAKEFILE=	makefile.autoconf
USE_GMAKE=	yes

.ifdef WITH_VOODOO3
CONFIGURE_ARGS+=	--enable-fx-glide-hw=h3
.elifdef WITH_VOODOO2
CONFIGURE_ARGS+=	--enable-fx-glide-hw=cvg
.endif

post-extract:
		( cd ${WRKSRC}; ${TAR} xfpz \
			${DISTDIR}/${PORTNAME:S/G/g/}-2001-01-06.tar.gz )

post-patch:
		( cd ${WRKSRC} ; aclocal )

.include <bsd.port.mk>
