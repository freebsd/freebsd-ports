# New ports collection makefile for:   Skribe
# Date created:                19 December 2003
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	skribe
PORTVERSION=	1.0a
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp-sop.inria.fr/mimosa/fp/Skribe/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	A highly programmable document processing system

BUILD_DEPENDS=	bigloo:${PORTSDIR}/lang/bigloo
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bigloo --prefix=${PREFIX} --docdir=${DOCSDIR}
USE_GMAKE=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	${REINPLACE_CMD} -e 's|^function ||' ${WRKSRC}/etc/skribe-config.in
	${REINPLACE_CMD} -e 's|$$prefix/doc/skribe-$$release|${DOCSDIR}|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|.*prcs.*|beta=|' ${WRKSRC}/etc/bigloo/configure
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's/= doc/=/' ${WRKSRC}/Makefile
.endif

post-build:
	${CHMOD} a+r ${WRKSRC}/doc/html/img/*.gif

post-install:
	${TOUCH} ${DATADIR}/extensions/.keep_me

.include <bsd.port.mk>
