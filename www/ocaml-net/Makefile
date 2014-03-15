# Created by: Stephane Legrand <stephane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	net
PORTVERSION=	3.5.1
CATEGORIES=	www
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml modules for Internet applications

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	ocaml-equeue-2* ocaml-netclient-0*

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
HAS_CONFIGURE=	yes

ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/netplex-admin \
		bin/ocamlrpcgen

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PKGNAMEPREFIX}${PORTNAME}
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

PORTDOCS=	*
PORTEXAMPLES=	*

OCAML_PKGDIRS=	netsys netshm equeue shell netstring rpc-generator \
		rpc pop smtp netclient netcgi2 netgssapi netplex \
		netcgi2-plex netcamlbox netmulticore rpc-auth-local
OCAML_LDLIBS=	${OCAML_PKGDIRS:S/^/${OCAML_SITELIBDIR}\//}

OPTIONS_DEFINE=	SSL NETHTTPD AUTH_DH GTK2 APACHE ZIP SCRAM EXAMPLES DOCS
OPTIONS_DEFAULT=	SSL
AUTH_DH_DESC=	Diffie-Hellman authorization support
NETHTTPD_DESC=	Integrated HTTP daemon
SCRAM_DESC=	SCRAM support
ZIP_DESC=	Compression support
APACHE_DESC=	Apache mod connector (experimental)

CONFIGURE_ARGS+=	-disable-gtk

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	-enable-ssl
BUILD_DEPENDS+=		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
RUN_DEPENDS+=		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
OCAML_PKGDIRS+=		equeue-ssl rpc-ssl
.else
CONFIGURE_ARGS+=	-disable-ssl
.endif

.if ${PORT_OPTIONS:MNETHTTPD}
CONFIGURE_ARGS+=	-with-nethttpd
OCAML_PKGDIRS+=		nethttpd nethttpd-for-netcgi2
.else
CONFIGURE_ARGS+=	-without-nethttpd
.endif

.if ${PORT_OPTIONS:MAUTH_DH}
CONFIGURE_ARGS+=	-with-rpc-auth-dh
BUILD_DEPENDS+=		${SA_DIR}/cryptgps/cryptgps.a:${PORTSDIR}/security/ocaml-cryptgps
RUN_DEPENDS+=		${SA_DIR}/cryptgps/cryptgps.a:${PORTSDIR}/security/ocaml-cryptgps
OCAML_PKGDIRS+=		rpc-auth-dh
.else
CONFIGURE_ARGS+=	-without-rpc-auth-dh
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	-enable-gtk2
BUILD_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
OCAML_PKGDIRS+=		equeue-gtk2
.else
CONFIGURE_ARGS+=	-disable-gtk2
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=		22+
CONFIGURE_ARGS+=	-enable-apache -apxs ${APXS} -apache ${HTTPD}
OCAML_PKGDIRS+=		netcgi_apache
.else
CONFIGURE_ARGS+=	-disable-apache
.endif

.if ${PORT_OPTIONS:MZIP}
CONFIGURE_ARGS+=	-enable-zip
BUILD_DEPENDS+=		${SA_DIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip
RUN_DEPENDS+=		${SA_DIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip
OCAML_PKGDIRS+=		netzip
.else
CONFIGURE_ARGS+=	-disable-zip
.endif

.if ${PORT_OPTIONS:MSCRAM}
CONFIGURE_ARGS+=	-enable-crypto
BUILD_DEPENDS+=		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit
RUN_DEPENDS+=		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit
OCAML_PKGDIRS+=		netmech-scram
.else
CONFIGURE_ARGS+=	-disable-crypto
.endif

post-patch:
	${REINPLACE_CMD} -e '/\.libs/d' \
		${WRKSRC}/src/netcgi2-apache/Makefile.def
	${REINPLACE_CMD} -e 's/camlzip/zip/' \
		${WRKSRC}/configure \
		${WRKSRC}/src/netzip/META.in \
		${WRKSRC}/src/netzip/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
