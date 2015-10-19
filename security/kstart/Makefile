# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kstart
DISTVERSION=	4.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Automated Kerberos ticket cache and keytab management utilities

USE_RC_SUBR=	${PORTNAME}
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/k5start bin/krenew \
		man/man1/k5start.1.gz man/man1/krenew.1.gz

do-install:
	@${GZIP_CMD} ${WRKSRC}/k5start.1
	@${GZIP_CMD} ${WRKSRC}/krenew.1
	${INSTALL_PROGRAM} ${WRKSRC}/k5start ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/krenew ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/k5start.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/krenew.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
