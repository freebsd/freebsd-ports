PORTNAME=	checkpassword-pam
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/checkpasswd-pam/checkpasswd-pam/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of checkpassword authentication program
WWW=		https://checkpasswd-pam.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/checkpassword-pam \
		share/man/man8/checkpassword-pam.8.gz

post-install:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
