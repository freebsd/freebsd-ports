PORTNAME=	kstart
DISTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Automated Kerberos ticket cache and keytab management utilities
WWW=		https://www.eyrie.org/~eagle/software/kstart/

USE_RC_SUBR=	${PORTNAME}
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/k5start bin/krenew \
		share/man/man1/k5start.1.gz share/man/man1/krenew.1.gz

do-install:
	@${GZIP_CMD} ${WRKSRC}/docs/k5start.1
	@${GZIP_CMD} ${WRKSRC}/docs/krenew.1
	${INSTALL_MAN} ${WRKSRC}/docs/k5start.1.gz ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/krenew.1.gz ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/commands/k5start ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/commands/krenew ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
