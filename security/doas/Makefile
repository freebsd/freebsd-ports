# $FreeBSD$

PORTNAME=	doas
PORTVERSION=	6.0p1
CATEGORIES=	security

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple sudo alternative to run commands as another user

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_ISCL=		${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	slicer69
GH_PROJECT=	doas

USES=	gmake

BINMODE=	4755

SUB_FILES=	pkg-message
PLIST_FILES=	bin/doas \
		man/man5/doas.conf.5.gz \
		man/man1/doas.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doas.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doas.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
