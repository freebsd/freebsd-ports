PORTNAME=	readarr
DISTVERSION=	0.3.10.2287
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Readarr/Readarr/releases/download/v${PORTVERSION}/
DISTNAME=	Readarr.develop.${DISTVERSION}.freebsd-core-x64

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Book Manager and Automation (Sonarr for Ebooks)
WWW=		https://readarr.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libiconv>0:converters/libiconv \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind

USES=	ssl:run sqlite:3

USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	YES

SUB_FILES=	${PORTNAME} package_info pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

WRKSRC=		${WRKDIR}/Readarr

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

.include <bsd.port.options.mk>

post-extract:
	${RM} -rf ${WRKSRC}/Readarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Readarr"
	${INSTALL_PROGRAM} ${WRKSRC}/Readarr ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
