# Created by: Peter Ankerstal <peter@pean.org>
# $FreeBSD$

PORTNAME=	sha2wordlist
PORTVERSION=	1.0.20140124
CATEGORIES=	security

MAINTAINER=	peter@pean.org
COMMENT=	Create SHA256 digests as PGP words

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	kirei
GH_TAGNAME=	3615281

PLIST_FILES=	sbin/sha2wordlist

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|cc|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/sbin/

.include <bsd.port.mk>
