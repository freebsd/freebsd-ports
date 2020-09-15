# $FreeBSD$

PORTNAME=	tlci
DISTVERSION=	0.1.0.2
CATEGORIES=	misc
MASTER_SITES=	https://gitlab.com/herrhotzenplotz/tlci/

MAINTAINER=	nsonack@outlook.com
COMMENT=	Tiny Lambda Calculus interpreter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	herrhotzenplotz
GL_COMMIT=	4a3dd51a872f36a513f06efa475922259dee91f1

PLIST_FILES=	${PREFIX}/bin/tlci \
		${PREFIX}/man/man8/tlci.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tlci

.include <bsd.port.mk>
