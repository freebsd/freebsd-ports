PORTNAME=	ookla-speedtest
PORTVERSION=	1.2.0
DISTVERSIONSUFFIX=	-freebsd${OSREL:R}-x86_64
CATEGORIES=	net
MASTER_SITES=	https://install.speedtest.net/app/cli/
EXTRACT_SUFX=	.pkg

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Internet connection measurement for developers
WWW=		https://www.speedtest.net/apps/cli

IGNORE_FreeBSD_14=	Upstream does not provide package for release
IGNORE_FreeBSD_15=	Upstream does not provide package for release
ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		libidn2>=0:dns/libidn2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/speedtest \
		share/man/man5/speedtest.5.gz

CONFLICTS_INSTALL=	py*-speedtest-cli # bin/speedtest

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/ ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/bin/speedtest ${STAGEDIR}${PREFIX}/bin/speedtest
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man5/speedtest.5 ${STAGEDIR}${PREFIX}/share/man/man5/speedtest.5

.include <bsd.port.mk>
