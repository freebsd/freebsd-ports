# Created by: Marko Njezic <sf@maxempire.com>
# $FreeBSD$

PORTNAME=	clamav-unofficial-sigs
PORTVERSION=	5.0.5
CATEGORIES=	security

MAINTAINER=	sf@maxempire.com
COMMENT=	Update script for third-party ClamAV databases

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	clamscan:security/clamav \
		rsync:net/rsync \
		curl:ftp/curl \
		gpg:security/gnupg \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	extremeshok

USES=		perl5 shebangfix
SHEBANG_FILES=	clamav-unofficial-sigs.sh
USE_PERL5=	run
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/clamav-unofficial-sigs.sh ${WRKSRC}/cron.d/clamav-unofficial-sigs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clamav-unofficial-sigs.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/clamav-unofficial-sigs.8 ${STAGEDIR}${MANPREFIX}/man/man8

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/master.conf ${STAGEDIR}${ETCDIR}/master.conf.sample
	${INSTALL_DATA} ${WRKSRC}/config/os.freebsd.conf ${STAGEDIR}${ETCDIR}/os.conf.sample
	${INSTALL_DATA} ${WRKSRC}/config/user.conf ${STAGEDIR}${ETCDIR}/user.conf.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} INSTALL LICENSE README.md ${STAGEDIR}${DOCSDIR})

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cron.d/clamav-unofficial-sigs ${STAGEDIR}${EXAMPLESDIR}/clamav-unofficial-sigs-cron
	${INSTALL_DATA} ${WRKSRC}/logrotate.d/clamav-unofficial-sigs ${STAGEDIR}${EXAMPLESDIR}/clamav-unofficial-sigs-logrotate

.include <bsd.port.mk>
