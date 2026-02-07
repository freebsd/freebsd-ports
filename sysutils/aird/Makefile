PORTNAME=	aird
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Handles Apple IR receiver button events
WWW=		https://wiki.freebsd.org/AppleMacbook

LICENSE=	BSD2CLAUSE

USE_RC_SUBR=	${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
