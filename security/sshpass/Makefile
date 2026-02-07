PORTNAME=	sshpass
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/sshpass/${PORTVERSION}

MAINTAINER=	gaod@hychen.org
COMMENT=	Non-interactive ssh password auth tool
WWW=		https://sourceforge.net/projects/sshpass/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/sshpass \
		share/man/man1/sshpass.1.gz

.include <bsd.port.mk>
