# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	chrony
PORTVERSION=	2.4.1
CATEGORIES=	net
MASTER_SITES=	http://download.tuxfamily.org/chrony/

MAINTAINER=	yonas@fizk.net
COMMENT=	System clock synchronization client and server

LICENSE=	GPLv2

BUILD_DEPENDS=	rubygem-asciidoctor>=0:textproc/rubygem-asciidoctor

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
EXTRAPORTDOCS=	FAQ NEWS README
PORTDOCS=	chrony.conf.html chronyc.html chronyd.html faq.html \
		installation.html ${EXTRAPORTDOCS}
PORTEXAMPLES=	chrony.conf.example1 chrony.conf.example2 \
		chrony.conf.example3 chrony.keys.example

# XXX: there are also other potentially useful options worth looking into:
#  --without-nss        Don't use NSS even if it is available
#  --without-tomcrypt   Don't use libtomcrypt even if it is available
#  --disable-pps        Disable PPS API support
OPTIONS_DEFINE=		IPV6

IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chronyc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/chronyd
	${INSTALL_DATA} ${EXTRAPORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/chrony.conf.example3 \
		${STAGEDIR}${PREFIX}/etc/chrony.conf.sample

.include <bsd.port.mk>
