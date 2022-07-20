PORTNAME=	translate
PORTVERSION=	1.20
CATEGORIES=	misc perl5
MASTER_SITES=	http://www.freebsdcluster.org/~mich/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translates string using Google Translate

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/translate man/man1/translate.1.gz
SHEBANG_FILES=	translate

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
