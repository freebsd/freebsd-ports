# Created by: Marko Njezic <sf@maxempire.com>
# $FreeBSD$

PORTNAME=	clamav-unofficial-sigs
PORTVERSION=	5.3.2
CATEGORIES=	security

MAINTAINER=	sf@maxempire.com
COMMENT=	Update script for third-party ClamAV databases

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

COMMON_DEPENDS=	clamscan:security/clamav \
		rsync:net/rsync \
		curl:ftp/curl \
		gpg:security/gnupg \
		bash:shells/bash
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	extremeshok

USES=		perl5 shebangfix
SHEBANG_FILES=	clamav-unofficial-sigs.sh
USE_PERL5=	run

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${CP} ${FILESDIR}/manpage.conf ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|g' ${WRKSRC}/manpage.conf

	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/clamav-unofficial-sigs.sh

do-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/bash ./clamav-unofficial-sigs.sh -c manpage.conf --install-man)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clamav-unofficial-sigs.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/clamav-unofficial-sigs.8 ${STAGEDIR}${MANPREFIX}/man/man8

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/master.conf ${STAGEDIR}${ETCDIR}/master.conf.sample
	${INSTALL_DATA} ${WRKSRC}/config/os.freebsd.conf ${STAGEDIR}${ETCDIR}/os.conf.sample
	${INSTALL_DATA} ${WRKSRC}/config/user.conf ${STAGEDIR}${ETCDIR}/user.conf.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} INSTALL LICENSE README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
