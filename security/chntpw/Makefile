# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	chntpw
PORTVERSION=	110511
PORTREVISION=	2
CATEGORIES=	security sysutils
MASTER_SITES=	http://pogostick.net/~pnh/ntpasswd/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Utility to set the password and edit registry on Microsoft NT system

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES=		gmake zip ssl

BIN_FILES=	chntpw cpnt reged
PLIST_FILES=	${BIN_FILES:C|^|bin/|}
PORTDOCS=	README.txt WinReg.txt regedit.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/d; /^OSSLPATH=/ s|=.*|=${OPENSSLBASE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CFLAGS=/ s| -m32||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:C|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
