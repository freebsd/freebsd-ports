PORTNAME=	multisort
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://www.xach.com/multisort/ \
		http://mirror.mcx2.org/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Small program to take multiple httpd logfiles into one
WWW=		https://www.xach.com/multisort/

LICENSE=	GPLv2+

PLIST_FILES=	bin/multisort

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/multisort

.include <bsd.port.mk>
