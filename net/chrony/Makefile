# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	chrony
PORTVERSION=	2.2
CATEGORIES=	net
MASTER_SITES=	http://download.tuxfamily.org/chrony/

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	System clock synchronization client and server

LICENSE=	GPLv2

# XXX: should theoretically work on others, but at least on PowerPC it dies
# with ``Could not open any NTP socket'' message on startup :(
ONLY_FOR_ARCHS=	i386 amd64

USES=		cpe gmake makeinfo readline
CPE_VENDOR=	tuxfamily
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--chronyvardir=/var/db/${PORTNAME} \
		--infodir=${PREFIX}/info \
		--sysconfdir=${PREFIX}/etc --mandir=${MANPREFIX}/man \
		--datarootdir=${DATADIR} --docdir=${DOCSDIR}
USE_RC_SUBR=	chronyd

ALL_TARGET=	all docs
INSTALL_TARGET=	install install-docs
INFO=		chrony
EXTRAPORTDOCS=	FAQ NEWS README
PORTDOCS=	chrony.html chrony.txt ${EXTRAPORTDOCS}
PORTEXAMPLES=	chrony.conf.example1 chrony.conf.example2 \
	chrony.conf.example3 chrony.keys.example

# XXX: there are also other potentially useful options worth looking into:
#  --without-nss        Don't use NSS even if it is available
#  --without-tomcrypt   Don't use libtomcrypt even if it is available
#  --disable-pps        Disable PPS API support
OPTIONS_DEFINE=		IPV6

IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chronyc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/chronyd
	cd ${WRKSRC}/${f} && \
		${INSTALL_DATA} ${EXTRAPORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} chrony.conf.example3 ${STAGEDIR}${PREFIX}/etc/chrony.conf.sample

.include <bsd.port.mk>
