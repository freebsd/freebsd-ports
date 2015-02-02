# $FreeBSD$

PORTNAME=	openntpd
PORTVERSION=	5.7p3
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenNTPD

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Network Time Protocol (NTP) daemon

LICENSE=	ISCL

USERS=		_ntp
GROUPS=		_ntp

USE_RC_SUBR=	openntpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--disable-silent-rules

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/ntpd.conf.5 ${WRKSRC}/ntpd.8

post-install:
	cd ${STAGEDIR}${PREFIX}/etc; ${MV} ntpd.conf ntpd.conf.sample

.include <bsd.port.mk>
