# $FreeBSD$

PORTNAME=	gvmd
DISTVERSION=	20.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Vulnerability Manager central management service

LICENSE=	AGPLv3+

BUILD_DEPENDS=	doxygen>0:devel/doxygen
LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libical.so:devel/libical
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
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

USES=		cmake gnome pkgconfig pgsql python samba:run
USE_GNOME=	glib20 libxslt:build
USE_LDCONFIG=	yes

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	gvmd

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/gvm/gvmd/gnupg
	@${MKDIR} ${STAGEDIR}/var/log/gvm
	@${MKDIR} ${STAGEDIR}/var/run/gvm

.include <bsd.port.mk>
