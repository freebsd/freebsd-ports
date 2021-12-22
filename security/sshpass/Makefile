# Created by: Hung-Yi Chen <gaod@hychen.org>

PORTNAME=	sshpass
PORTVERSION=	1.09
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/sshpass/${PORTVERSION}

MAINTAINER=	gaod@hychen.org
COMMENT=	Non-interactive ssh password auth tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sshpass \
		man/man1/sshpass.1.gz

.include <bsd.port.mk>
