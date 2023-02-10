PORTNAME=	tigervnc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
CATEGORIES=	net x11-servers

MAINTAINER?=	meta@FreeBSD.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

USES+=		cmake:insource,noninja cpe
USE_GITHUB=	yes

GH_ACCOUNT=	TigerVNC
CONFLICTS=	tightvnc
PLIST_SUB+=	TIGERVNC_COMPONENT=${PORTNAME}${PKGNAMESUFFIX}-

CMAKE_ARGS+=	-G "Unix Makefiles" -DINSTALL_SYSTEMD_UNITS:BOOL=false
MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}

DOCS=	LICENCE.TXT README.rst

.include <bsd.port.pre.mk>

PLIST=	${.CURDIR}/pkg-plist

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${DOCSDIR}/${PORTNAME}${PKGNAMESUFFIX}-${f})
.endfor

.include <bsd.port.post.mk>
