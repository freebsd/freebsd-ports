# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	chrony
PORTVERSION=	1.31
CATEGORIES=	net
MASTER_SITES=	http://download.tuxfamily.org/chrony/

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	System clock synchronization client and server

LICENSE=	GPLv2

# XXX: should theoretically work on others, but at least on PowerPC it dies
# with ``Could not open any NTP socket'' message on startup :(
ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake makeinfo readline
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc --mandir=${MANPREFIX}/man \
		--datarootdir=${DATADIR} --docdir=${DOCSDIR}
USE_RC_SUBR=	chronyd

PORTDOCS=	COPYING README chrony.txt

# XXX: there are also other potentially useful options worth looking into:
#  --without-nss        Don't use NSS even if it is available
#  --without-tomcrypt   Don't use libtomcrypt even if it is available
#  --disable-pps        Disable PPS API support
OPTIONS_DEFINE=		IPV6
OPTIONS_DEFAULT=	IPV6

IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6

post-install:
.for f in chrony.conf.example chrony.conf.example2 chrony.keys.example
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${PREFIX}/etc
.endfor

.include <bsd.port.mk>
