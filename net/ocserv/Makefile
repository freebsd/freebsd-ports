# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	ocserv
PORTVERSION=	0.11.7
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.infradead.org/pub/ocserv/

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Server implementing the AnyConnect SSL VPN protocol

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	autogen:devel/autogen \
		gsed:textproc/gsed \
		bash:shells/bash
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libiconv.so:converters/libiconv \
		libtalloc.so:devel/talloc \
		libprotobuf-c.so:devel/protobuf-c \
		libgnutls.so:security/gnutls \
		libtasn1.so:security/libtasn1 \
		libev.so:devel/libev \
		libnettle.so:security/nettle

USES=		autoreconf cpe gmake gperf libtool localbase ncurses \
		pathfix pkgconfig readline tar:xz
CPE_VENDOR=	infradead
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-nls \
		--enable-local-libopts \
		--without-http-parser \
		--without-pcl-lib \
		--without-radius

USERS=		_ocserv
GROUPS=		_ocserv

USE_RC_SUBR=	ocserv

PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"

OPTIONS_DEFINE=		DOCS EXAMPLES GSSAPI

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTEXAMPLES=	profile.xml sample.config sample.passwd

GSSAPI_USES=		gssapi:mit
GSSAPI_LIB_DEPENDS=	libkrb5support.so:security/krb5
GSSAPI_CONFIGURE_OFF=	--without-gssapi

post-patch:
	@${RM} ${WRKSRC}/doc/*.8

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/ocserv
	@${MKDIR} ${STAGEDIR}/var/run/ocserv
	${INSTALL_DATA} ${FILESDIR}/ocserv.conf ${STAGEDIR}${PREFIX}/etc/ocserv/conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
