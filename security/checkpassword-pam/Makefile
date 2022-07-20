PORTNAME=	checkpassword-pam
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/checkpasswd-pam/checkpasswd-pam/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of checkpassword authentication program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/checkpassword-pam \
		man/man8/checkpassword-pam.8.gz

post-install:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
