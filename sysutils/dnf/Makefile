# $FreeBSD$

PORTNAME=	dnf
DISTVERSION=	4.4.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dandified YUM, the next-generation version of YUM

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	libcomps>0:misc/libcomps \
		libdnf>0:sysutils/libdnf \
		rpm4>0:archivers/rpm4 \
		${PYTHON_PKGNAMEPREFIX}gpgme>0:security/py-gpgme@${PY_FLAVOR}

USES=		cmake gettext-tools python
USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management
GH_PROJECT=	dnf

CMAKE_OFF=	FREEBSD_INSTALL_DOC
CMAKE_ARGS=	-DPYTHON_DESIRED=${PYTHON_MAJOR_VER}

INSTALL_TARGET=	install

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|'/usr/bin'|'${PREFIX}/bin'|" ${WRKSRC}/bin/dnf*.in

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} -s dnf-3 dnf && \
		${LN} -s dnf-automatic-3 dnf-automatic

.include <bsd.port.mk>
