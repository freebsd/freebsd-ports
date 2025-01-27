PORTNAME=	usacloud
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Meta port for SAKURA cloud
WWW=		https://docs.usacloud.jp/usacloud/

LICENSE=	APACHE20

BUILD_DEPENDS=	usacloud-core>=${PKGVERSION}:sysutils/usacloud-core
RUN_DEPENDS=	usacloud-core>=${PKGVERSION}:sysutils/usacloud-core

NO_ARCH=	yes
NO_TEST=	yes
NO_WRKSUBDIR=	yes

USACLOUD_CMD=	${LOCALBASE}/bin/usacloud completion
ENTRIES=	bash:etc/bash_completion.d/usacloud \
		zsh:share/zsh/site-functions/_usacloud
M_LABEL=	C,\:.*$$,,
M_PATH=		C,^.*\:,,
PLIST_FILES=	${ENTRIES:${M_PATH}}

do-build:
	cd ${BUILD_WRKSRC} && \
	   ${MKDIR} ${ENTRIES:${M_PATH}:H} && \
	   ${ENTRIES:@F@${USACLOUD_CMD} ${F:${M_LABEL}} > ${F:${M_PATH}};@}

do-install:
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}

.include "${.CURDIR}/../usacloud-core/Makefile.version"
.include <bsd.port.mk>
