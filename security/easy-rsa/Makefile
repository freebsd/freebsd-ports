# $FreeBSD$

PORTNAME=	easy-rsa
DISTVERSION=	3.0.6
CATEGORIES=	security net-mgmt
MASTER_SITES=	https://github.com/OpenVPN/easy-rsa/releases/download/v${DISTVERSION}/
DISTNAME=	EasyRSA-unix-v${DISTVERSION}

# Eric F. Crist <ecrist@secure-computing.net> does not require my
# approval for changes to this package. -- mandree@FreeBSD.org
MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Small RSA key management package based on openssl

LICENSE=	GPLv2

CONFLICTS_INSTALL=easy-rsa2-*

USES=		tar:tgz
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/EasyRSA-v${DISTVERSION}

PATCH_STRIP=	-p2

OPTIONS_DEFINE=		DOCS EXAMPLES

PORTDATA=	x509-types/
_pd_files=	ChangeLog COPYING.md README.md README.quickstart.md
_pd_dirs=	doc/
PORTDOCS=	${_pd_files} ${_pd_dirs}

SUB_FILES=	easyrsa

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DATADIR}/x509-types/
		${INSTALL_SCRIPT} ${WRKDIR}/easyrsa ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_SCRIPT} ${WRKSRC}/easyrsa ${STAGEDIR}${DATADIR}/easyrsa.real
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
