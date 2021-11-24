# Created by: Jim Geovedi <jim@corebsd.or.id>

PORTNAME=	kripp
PORTVERSION=	0.6.1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/sniffers \
		http://konst.org.ua/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight network password sniffer

DEPRECATED=	Abandonware, upstream returns 404 and last release was back in 2007
EXPIRATION_DATE=2022-03-31

USES=		perl5 shebangfix
USE_PERL5=	run

NO_BUILD=	yes

PLIST_FILES=	bin/kripp man/man1/kripp.1.gz
SHEBANG_FILES=	kripp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kripp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kripp.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
