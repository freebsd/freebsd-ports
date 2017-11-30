# Created by: ijliao
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python module for the libnet packet construction library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnet.so:net/libnet

BROKEN_armv6=		fails to package: lib.freebsd-11.0-RELEASE-p1-armv6-2.7/libnet.so: No such file or directory
BROKEN_armv7=		fails to package: lib.freebsd-11.0-RELEASE-p1-armv7-2.7/libnet.so: No such file or directory
BROKEN_aarch64=		fails to package: lib.freebsd-11.0-RELEASE-p1-aarch64-2.7/libnet.so: No such file or directory
BROKEN_mips64=		fails to package: lib.freebsd-11.0-RELEASE-p1-mips64-2.7/libnet.so: No such file or directory
BROKEN_powerpc64=	fails to package: lib.freebsd-11.0-RELEASE-p1-powerpc64-2.7/libnet.so: No such file or directory

USES=		python:-2.7
USE_PYTHON=	distutils pythonprefix

USE_GITHUB=	yes
GH_ACCOUNT=	allfro
GH_PROJECT=	pylibnet
GH_TAGNAME=	b2fa552

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES
OSVER=		uname -r

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} \
	${WRKSRC}/build/lib.${OPSYS:tl}-$$(${OSVER})-${ARCH}-${PYTHON_VER}/${PORTNAME}.so \
	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
