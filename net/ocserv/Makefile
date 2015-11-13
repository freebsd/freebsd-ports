# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	ocserv
PORTVERSION=	0.10.9
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.infradead.org/pub/ocserv/

MAINTAINER=	cpm@fbsd.es
COMMENT=	Server implementing the AnyConnect SSL VPN protocol

LICENSE=	GPLv2

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		gsed:${PORTSDIR}/textproc/gsed \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	liblz4.so:${PORTSDIR}/archivers/liblz4 \
		libiconv.so:${PORTSDIR}/converters/libiconv \
		libtalloc.so:${PORTSDIR}/devel/talloc \
		libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libtasn1.so:${PORTSDIR}/security/libtasn1

USES=		autoreconf cpe gettext gmake gperf libtool ncurses \
		pathfix pkgconfig readline tar:xz
CPE_VENDOR=	infradead
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
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

OPTIONS_DEFINE=		DOCS EXAMPLES GSSAPI

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO
PORTEXAMPLES=	profile.xml sample.config sample.passwd

GSSAPI_USES=		gssapi:mit
GSSAPI_LIB_DEPENDS=	libkrb5support.so:${PORTSDIR}/security/krb5
GSSAPI_CONFIGURE_OFF=	--without-gssapi

post-patch:
	${RM} ${WRKSRC}/doc/occtl.8
	${RM} ${WRKSRC}/doc/ocpasswd.8
	${RM} ${WRKSRC}/doc/ocserv.8

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/occtl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ocpasswd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/ocserv
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ocserv/
	${MKDIR} ${STAGEDIR}/var/run/ocserv/
	${CP} ${FILESDIR}/ocserv.conf ${STAGEDIR}${PREFIX}/etc/ocserv/conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
