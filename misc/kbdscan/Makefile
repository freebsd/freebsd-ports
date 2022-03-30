PORTNAME=	kbdscan
PORTVERSION=	20110507
CATEGORIES=	misc
MASTER_SITES=	https://hack.org/mc/hacks/kbdscan/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Show scancodes of keys pressed and released

LICENSE=	ISCL

USES=		tar:bzip2

PLIST_FILES=	bin/kbdscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kbdscan ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
