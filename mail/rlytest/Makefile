# Created by: Paul Chvostek <paul@it.ca>

PORTNAME=	rlytest
PORTVERSION=	1.22
CATEGORIES=	mail security
MASTER_SITES=	http://www.unicom.com/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test remote system for unsecured mail relay

BROKEN=		Unfetchable
DEPRECATED=	Abandonware, last release in 2003 and dead upstream
EXPIRATION_DATE=2022-03-31

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}

NO_WRKSUBDIR=	yes

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}

PLIST_FILES=	bin/rlytest man/man1/rlytest.1.gz

do-build:
	@cd ${WRKSRC} && pod2man ${PORTNAME} > ${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
