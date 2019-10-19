# Created by: gahr
# $FreeBSD$

PORTNAME=	mbox2imap
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://BSDforge.com/projects/source/mail/mbox2imap/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Upload email stored in mbox file format to an IMAP server

LICENSE=	NONE

USES=		python shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
