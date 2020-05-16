# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	chrony
PORTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://download.tuxfamily.org/chrony/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	System clock synchronization client and server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake libedit pkgconfig

CPE_VENDOR=	tuxfamily

USE_RC_SUBR=	chronyd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--chronyvardir=/var/db/${PORTNAME} \
		--sysconfdir=${PREFIX}/etc --mandir=${MANPREFIX}/man \
		--datarootdir=${DATADIR} --docdir=${DOCSDIR} \
		--with-readline-library=${LOCALBASE}/lib \
		--without-tomcrypt

ALL_TARGET=	all
INSTALL_TARGET=	install
PORTDOCS=	FAQ NEWS README
PORTEXAMPLES=	chrony.conf.example1 chrony.conf.example2 \
		chrony.conf.example3 chrony.keys.example

# XXX: there are also other potentially useful options worth looking into:
#  --disable-pps        Disable PPS API support
OPTIONS_DEFINE=		DOCS HTMLDOCS EXAMPLES IPV6 USER
OPTIONS_DEFAULT=	NETTLE USER
OPTIONS_RADIO=		CRYPTLIB
OPTIONS_RADIO_CRYPTLIB=	NETTLE NSS
OPTIONS_SUB=		yes

HTMLDOCS_DESC=		Build HTML docs (IMPLIES DOCS, needs ruby, asciidoctor)
NETTLE_DESC=		Nettle crypto library support
NSS_DESC=		NSS-based support for more hashing algorithms
USER_DESC=		Run as user/group chronyd (unset: user/group ntpd)

HTMLDOCS_IMPLIES=	DOCS

HTMLDOCS_BUILD_DEPENDS+=asciidoctor:textproc/rubygem-asciidoctor
HTMLDOCS_ALL_TARGET=	docs
HTMLDOCS_INSTALL_TARGET=docs
IPV6_CONFIGURE_OFF=	--disable-ipv6
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NETTLE_CONFIGURE_OFF=	--without-nettle
NSS_LIB_DEPENDS=	libfreebl3.so:security/nss
NSS_CONFIGURE_OFF=	--without-nss
USER_CONFIGURE_ON=	--with-user=chronyd
USER_CONFIGURE_OFF=	--with-user=ntpd

USER_VARS=		USERS=chronyd GROUPS=chronyd

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MHTMLDOCS}
PORTDOCS+=		doc/*.html
.endif

post-patch:
	cd ${WRKSRC}/examples && \
		${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!g' ${PORTEXAMPLES}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chronyc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/chronyd
	${INSTALL_DATA} ${WRKSRC}/examples/chrony.conf.example3 \
		${STAGEDIR}${PREFIX}/etc/chrony.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RM} doc/installation.html
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
