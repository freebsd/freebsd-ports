PORTNAME=	ised
PORTVERSION=	2.7.1
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Tool for generating number sequences and arithmetic evaluation
WWW=		https://ised.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libedit tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
