# $FreeBSD$

PORTNAME=	openntpd
PORTVERSION=	6.0p1
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenNTPD

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Network Time Protocol (NTP) daemon

LICENSE=	ISCL

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USE_RC_SUBR=	openntpd
USERS=		_ntp
GROUPS=		_ntp

USES=		ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cacert=${LOCALBASE}/etc/ssl/cert.pem

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/src/ntpd.conf.5 ${WRKSRC}/src/ntpd.8

post-install:
	cd ${STAGEDIR}${PREFIX}/etc && ${MV} ntpd.conf ntpd.conf.sample

.include <bsd.port.pre.mk>

# Requires libtls from LibreSSL
.if ${SSL_DEFAULT:Mlibressl*}
CPPFLAGS+=		-I${OPENSSLINC}
LDFLAGS+=		-L${OPENSSLLIB}
.else # SSL_DEFAULT
BUILD_DEPENDS+=		${NONEXISTENT}:security/libressl:stage
CPPFLAGS+=		-I${WRKDIR}/libressl/include
LDFLAGS+=		-L${WRKDIR}/libressl/lib
# security/libressl ignores implicit SSP_UNSAFE, see Mk/bsd.ssp.mk
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000036 && ${ARCH} == i386
SSP_CFLAGS?=	-fstack-protector
CFLAGS+=	${SSP_CFLAGS}
LDFLAGS+=	-fstack-protector
LIBS+=		-lssp_nonshared
. endif

# Don't use COPYTREE_SHARE here as it hard links files, and the original files
# are owned by root, which creates problems of its own.
pre-configure:
	@cd `${MAKE} -V STAGEDIR -C ${PORTSDIR}/security/libressl`${PREFIX} \
	    && ${FIND} -E . ! -name *.so\* | ${CPIO} -dump ${WRKDIR}/libressl >/dev/null 2>&1
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
