# Ports collection Makefile for:	nss
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nss
PORTVERSION=	3.8
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	security/nss/releases/NSS_${PORTVERSION:S/./_/g}_RTM/src

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of libraries to support development of security-enabled applications

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/security/nss

USE_PERL5_BUILD=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
MAKE_ENV=	BSD_LDOPTS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		BUILD_OPT=1
ALL_TARGET=	nss_build_all
CFLAGS+=	-I${LOCALBASE}/include/nspr

DIST=		${WRKSRC}/../../dist

CONFLICTS=	btoa-5.* digest-* emboss-2.4.* oases-2.* p5-PAR-0.*

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/../../security/coreconf/FreeBSD.mk

do-install:
	${MKDIR} ${PREFIX}/include/nss
	${TAR} -C ${DIST}/public --dereference -cf - . | \
		${TAR} -C ${PREFIX}/include/nss -xf -
	${INSTALL_PROGRAM} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib/*.so.1 \
		${PREFIX}/lib
	${INSTALL_PROGRAM} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/bin/* \
		${PREFIX}/bin
	cd ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib && \
		${TAR} -cf - *.so | ${TAR} --unlink -C ${PREFIX}/lib -xf -

.include <bsd.port.mk>
