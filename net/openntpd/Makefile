PORTNAME=	openntpd
PORTVERSION=	6.8p1
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenNTPD

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Network Time Protocol (NTP) daemon

LICENSE=	ISCL

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe localbase ssl

CONFLICTS=	ntp ntp-devel ntpsec

USE_RC_SUBR=	openntpd
USERS=		_ntp
GROUPS=		_ntp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cacert=${LOCALBASE}/etc/ssl/cert.pem

SUB_FILES=	480.status-openntpd pkg-message
SUB_LIST=	MANPREFIX="${MANPREFIX}"

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/src/ntpd.conf.5 ${WRKSRC}/src/ntpd.8

post-install:
	cd ${STAGEDIR}${PREFIX}/etc && ${MV} ntpd.conf ntpd.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/480.status-openntpd \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.pre.mk>

# When using LibreSSL use its own libtls, but when using OpenSSL
# use libtls from libretls.
.if ${SSL_DEFAULT:Mlibressl*}
#	/* empty */
.else
LIB_DEPENDS+=	libtls.so:security/libretls
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
