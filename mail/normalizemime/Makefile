# New ports collection makefile for:	normalize mime
# Date created:		Wed Aug 31 00:24:53 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	normalizemime
PORTVERSION=	1.16.20050628
CATEGORIES=	mail
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/spam/
DISTNAME=	normalizemime.cc
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A mime normalizer to be used as a preprocessor for email classication

USE_ICONV=	yes
NO_WRKSUBDIR=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

PLIST_FILES=	bin/${DISTNAME:R}

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${CXX} ${CXXFLAGS} ${LDFLAGS} \
		${DISTNAME} -o ${DISTNAME:R}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:R} ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=3.4+
.endif

.include <bsd.port.post.mk>
