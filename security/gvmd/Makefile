PORTNAME=	gvmd
DISTVERSION=	26.0.0
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Vulnerability Manager central management service
WWW=		https://github.com/greenbone/gvmd

LICENSE=	AGPLv3+

BUILD_DEPENDS=	doxygen>0:devel/doxygen
LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libical.so:devel/libical
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${LOCALBASE}/lib/postgresql/libpg-gvm.so:databases/pg-gvm \
		doxygen>0:devel/doxygen \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		snmpget:net-mgmt/net-snmp \
		rsync:net/rsync \
		wget:ftp/wget \
		gpg:security/gnupg \
		xml:textproc/xmlstarlet \
		sshpass:security/sshpass \
		socat:net/socat \
		zip:archivers/zip

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone

USES=		cmake gnome pkgconfig pgsql python samba:run shebangfix
USE_GNOME=	glib20 libxslt:build
USE_LDCONFIG=	yes

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	gvmd

SHEBANG_FILES=	tools/gvm-lsc-rpm-creator \
		tools/gvm-lsc-deb-creator \
		src/alert_methods/TippingPoint/report-convert.py \
		src/alert_methods/SCP/alert \
		src/alert_methods/SMB/alert

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/manage_sql.c
	${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>||g' ${WRKSRC}/src/manage.c \
		${WRKSRC}/src/gvmd.c ${WRKSRC}/src/manage_sql_secinfo.c

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/gvm/gvmd/gnupg
	@${MKDIR} ${STAGEDIR}/var/log/gvm
	@${MKDIR} ${STAGEDIR}/var/run/gvmd

.include <bsd.port.mk>
