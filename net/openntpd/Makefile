PORTNAME=	openntpd
PORTVERSION=	6.8p1
PORTREVISION=	10
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenNTPD

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Network Time Protocol (NTP) daemon
WWW=		https://www.openntpd.org/

LICENSE=	ISCL

USES=		cpe localbase ssl

CONFLICTS=	ntp ntp-devel ntpsec

USE_RC_SUBR=	openntpd
USERS=		_ntp
GROUPS=		_ntp

GNU_CONFIGURE=	yes

SUB_FILES=	480.status-openntpd pkg-message

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/src/ntpd.conf.5 ${WRKSRC}/src/ntpd.8

post-install:
	cd ${STAGEDIR}${PREFIX}/etc && ${MV} ntpd.conf ntpd.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/480.status-openntpd \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.pre.mk>

# certificate bundle
.if !(${OPSYS} == FreeBSD && ${OSVERSION} >= 1500063)
RUN_DEPENDS+=	ca_root_nss>=0:security/ca_root_nss
.endif

# When using LibreSSL use its own libtls, but when using OpenSSL
# use libtls from libretls.
.if ${SSL_DEFAULT:Mlibressl*}
#	/* empty */
.else
LIB_DEPENDS+=	libtls.so:security/libretls
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
