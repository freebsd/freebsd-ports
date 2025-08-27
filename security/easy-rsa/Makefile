PORTNAME=	easy-rsa
DISTVERSION=	3.2.4
PORTREVISION=	0  # leave in if 0 to avoid accidental PORTEPOCH bumps
PORTEPOCH=	1
CATEGORIES=	security net-mgmt
MASTER_SITES=	https://github.com/OpenVPN/easy-rsa/releases/download/v${DISTVERSION}/ \
		LOCAL/mandree/
DISTFILES=	EasyRSA-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Small RSA key management package based on openssl
WWW=		https://github.com/OpenVPN/easy-rsa

LICENSE=	GPLv2

USES=		tar:tgz

PATCH_STRIP=	-p1

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/EasyRSA-${DISTVERSION}

PORTDATA=	x509-types/
_pd_files=	ChangeLog COPYING.md README.md README.quickstart.md
_pd_dirs=	doc/
PORTDOCS=	${_pd_dirs} ${_pd_files}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DATADIR}/x509-types/
		${INSTALL_SCRIPT} ${WRKSRC}/easyrsa ${STAGEDIR}${PREFIX}/bin/
		${LN} -fh ${STAGEDIR}${PREFIX}/bin/easyrsa ${STAGEDIR}${PREFIX}/bin/easy-rsa
		${INSTALL_DATA} ${WRKSRC}/vars.example ${STAGEDIR}${DATADIR}/
		${INSTALL_DATA} ${WRKSRC}/openssl-easyrsa.cnf ${STAGEDIR}${DATADIR}/openssl-easyrsa.cnf.example
		(cd ${WRKSRC}/x509-types/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/x509-types/)

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${_pd_files}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${_pd_dirs}
		${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
		(cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${i})
.endfor

.include <bsd.port.mk>
