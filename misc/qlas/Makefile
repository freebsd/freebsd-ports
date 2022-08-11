PORTNAME=	qlas
PORTVERSION=	1.93
CATEGORIES=	misc
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/qlas/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qico FIDO mailer log analyzer and statistic builder

USES=		shebangfix perl5 dos2unix
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/qlas etc/qlas.conf.default
SHEBANG_FILES=	qlas

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qlas ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qlas.conf.default ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
