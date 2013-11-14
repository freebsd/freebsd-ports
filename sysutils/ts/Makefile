# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ts
PORTVERSION=	0.7.4
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/ts/ CENKES

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Serial task spooler

USES=		gmake
PLIST_FILES=	bin/ts \
		man/man8/ts.8.gz
PORTDOCS=	OBJECTIVES PROTOCOL README TRICKS

post-patch:
	${REINPLACE_CMD} -e '/^GLIBCFLAGS/d;/^CFLAGS/d'\
		${WRKSRC}/Makefile

# Install man page as ts.8 to avoid conflict with security/openssl
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ts ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ts.1 ${STAGEDIR}${MAN1PREFIX}/man/man8/ts.8
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
