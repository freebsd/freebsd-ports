PORTNAME=	ladvd
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=v
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimal LLDP/CDP/EDP/FDP/NDP sender daemon
WWW=		https://github.com/sspans/ladvd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USERS=		ladvd
GROUPS=		${USERS}

USE_GITHUB=	yes
GH_ACCOUNT=	sspans
USES=		autoreconf libtool pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-chroot-dir=/var/empty

PORTDOCS=	README TODO HACKING
USE_RC_SUBR=	ladvd
SUB_FILES=	pkg-message

PLIST_FILES=	share/man/man8/ladvd.8.gz \
		share/man/man8/ladvdc.8.gz \
		sbin/ladvd \
		sbin/ladvdc

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|LICENSE||' ${WRKSRC}/doc/Makefile.am

.include <bsd.port.mk>
