# $FreeBSD$

PORTNAME=	reaver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.6
CATEGORIES=	net

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Reaver brute force attack against WPS (Wi-Fi Protected Setup)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../docs/LICENSE

USES=		compiler:c++11-lang gmake
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	t6x
GH_PROJECT=	${PORTNAME}-wps-fork-t6x

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/reaver \
		bin/wash \
		man/man1/reaver.1.gz

post-install:
		@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/reaver bin/wash
		@${RM} -r ${STAGEDIR}/var/lib
		${INSTALL_MAN} ${WRKSRC}/../docs/reaver.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
