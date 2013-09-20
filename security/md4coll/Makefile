# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	md4coll
DISTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	http://www.stachliu.com/ \
		http://mirror.roe.ch/dist/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}.c
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast MD4 collision generator

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
post-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${DISTNAME} -o ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
