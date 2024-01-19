PORTNAME=	ripmime
PORTVERSION=	1.4.1.0
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Extracts attached files out of a MIME encoded email package
WWW=		https://github.com/inflex/ripMIME

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	inflex
WRKSRC=		${WRKDIR}/ripMIME-${PORTVERSION}
PLIST_FILES=	bin/ripmime share/man/man1/ripmime.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's!^CFLAGS=!CFLAGS ?=!' \
		${WRKSRC}/Makefile ${WRKSRC}/ripOLE/Makefile \
		${WRKSRC}/tnef/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
