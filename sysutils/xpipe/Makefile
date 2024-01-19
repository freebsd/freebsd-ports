PORTNAME=	xpipe
DISTVERSION=	g20200503
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Split input and feed it into the given utility
WWW=		https://github.com/jschauma/xpipe

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	jschauma
GH_TAGNAME=	60b0aec

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
