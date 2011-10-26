# New ports collection makefile for:   Skribe
# Date created:                19 December 2003
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	skribe
PORTVERSION=	1.2l
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp-sop.inria.fr/mimosa/fp/Skribe/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A highly programmable document processing system

BUILD_DEPENDS=	bigloo:${PORTSDIR}/lang/bigloo
RUN_DEPENDS=	bigloo:${PORTSDIR}/lang/bigloo

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bigloo --prefix=${PREFIX} --docdir=${DOCSDIR}
PLIST_SUB=	VERSION="${PORTVERSION}"

BROKEN=		broken after lang/bigloo update

.SILENT:

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

post-patch:
	${REINPLACE_CMD} -e 's|^function ||' ${WRKSRC}/etc/skribe-config.in
	${REINPLACE_CMD} -e '/doc/d' ${WRKSRC}/Makefile

post-build:
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE})
.endif

post-install:
	${TOUCH} ${DATADIR}/extensions/.keep_me
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} install)
.endif

.include <bsd.port.mk>
