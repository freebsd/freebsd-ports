# New ports collection makefile for:	Direct Connect Text Client
# Date created:				Thu Nov 22 00:19:27 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.59
CATEGORIES=	net
MASTER_SITES=	http://ac2i.tzo.com/dctc/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GLIB=	yes
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lgnugetopt"
ALL_TARGET=

DOC_FILES=      COPYING ChangeLog INSTALL README \
		Documentation/DCextension Documentation/commands \
		Documentation/output Documentation/programs
PROGRAM_FILES= dc_hublist dctc

post-patch:
	@${PERL} -pi -e 's/(CK?\(std)(out\))/\1_\2/' ${BUILD_WRKSRC}/*

do-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} depend

do-install:
.for file in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${file} ${PREFIX}/bin
.endfor
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
