# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	normalizemime
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/spam/
DISTNAME=	normalizemime.cc
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mime normalizer to be used as a preprocessor for email classification

LICENSE=	GPLv2

USES=		iconv
NO_WRKSUBDIR=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PLIST_FILES=	bin/${DISTNAME:R}

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${CXX} ${CXXFLAGS} ${LDFLAGS} \
		${DISTNAME} -o ${DISTNAME:R}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:R} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
