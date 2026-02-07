PORTNAME=	openldap
PORTVERSION=	2.6.8
DISTVERSIONSUFFIX=	-4.el9.0.1
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	LDAP libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.OpenLDAP.org/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	cyrus-sasl2 nspr nss
USE_LINUX_RPM=	yes
USE_LINUX32=	yes

BIN_DISTNAMES=	${PORTNAME}-clients-${DISTVERSIONFULL}
LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-compat-${DISTVERSIONFULL} \

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}26-server/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

# do not install any openldap configuration directories/files
post-patch:
	@${RM} -r ${WRKSRC}/etc

# use a native openldap configuration directories/files
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -sf ${LOCALBASE}/etc/openldap ${STAGEDIR}${PREFIX}/etc/openldap

.include <bsd.port.mk>
