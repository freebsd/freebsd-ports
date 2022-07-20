PORTNAME=	opencryptoki
PORTVERSION=	3.18.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Open PKCS\#11 implementation library

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtspi.so:security/trousers \
		libepoll-shim.so:devel/libepoll-shim

USES=		alias autoreconf bison gmake libtool localbase ssl tar:tgz
USE_OPENLDAP=	yes
USE_LDCONFIG=	${PREFIX}/lib/opencryptoki
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
CONFIGURE_ARGS=	--enable-swtok \
		--enable-tpmtok \
		--enable-icsftok \
		--disable-crtok \
		--disable-aeptok \
		--disable-ccatok \
		--disable-bcomtok \
		--disable-pkcscca_migrate \
		--with-lockdir=/var/run/opencryptoki \
		--with-logdir=/var/log/opencryptoki \
		--localstatedir=/var \
		--with-openssl=${OPENSSLBASE} \
		--with-pkcs11user=${USERS} \
		--with-pkcs11group=${GROUPS} \
		ac_cv_path_CHGRP=true
INSTALL_TARGET=	install-strip
USE_RC_SUBR=	pkcsslotd
SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"
USERS=		_pkcs11
GROUPS=		_pkcs11

post-patch:
	cd ${WRKSRC} && \
	    ${REINPLACE_CMD} 's,%%DLLDIR%%,${PREFIX}/lib/opencryptoki/stdll,' \
	    usr/sbin/pkcsslotd/opencryptoki.conf

post-install:
	${MV} ${STAGEDIR}${DOCSDIR}/strength-example.conf \
	    ${STAGEDIR}${ETCDIR}/strength.conf.sample
	${MV} ${STAGEDIR}${DOCSDIR}/policy-example.conf \
	    ${STAGEDIR}${ETCDIR}/policy.conf.sample
	${RMDIR} ${STAGEDIR}/var/run/opencryptoki/* \
	    ${STAGEDIR}/var/run/opencryptoki

.include <bsd.port.mk>
