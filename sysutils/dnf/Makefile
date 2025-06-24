PORTNAME=	dnf
DISTVERSION=	4.22.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dandified YUM, the next-generation version of YUM
WWW=		https://github.com/rpm-software-management/dnf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	libcomps>0:misc/libcomps \
		libdnf>0:sysutils/libdnf \
		rpm4>0:archivers/rpm4 \
		${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR}

USES=		cmake gettext-tools python

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management

CMAKE_OFF=	FREEBSD_INSTALL_DOC
CMAKE_ARGS=	-DPYTHON_DESIRED=${PYTHON_MAJOR_VER}

INSTALL_TARGET=	install

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "\
		s|'/usr/bin'|'${PREFIX}/bin'|;\
		s|@PYTHON_EXECUTABLE@|${PYTHON_CMD}|\
		" ${WRKSRC}/bin/dnf*.in

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} -s dnf-3 dnf && \
		${LN} -s dnf-automatic-3 dnf-automatic

.include <bsd.port.mk>
