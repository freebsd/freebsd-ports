PORTNAME=	spm
PORTVERSION=	0.20200208
CATEGORIES=	security
MASTER_SITES=	https://notabug.org/kl3/spm/archive/
DISTNAME=	f920ab3f68

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple password manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gpg2:security/gnupg \
		tree:sysutils/tree

PLIST_FILES=	bin/spm \
		man/man1/spm.1.gz

WRKSRC=		${WRKDIR}/spm
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	  ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/spm.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
