# Created by: Stephane Legrand <stephane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	net
PORTVERSION=	3.7.3
CATEGORIES=	www
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml modules for Internet applications

LICENSE=	GPLv2

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

CONFLICTS=	ocaml-equeue-2* ocaml-netclient-0*

USES=			gmake
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
HAS_CONFIGURE=		yes

ALL_TARGET=		all opt
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
		netcgi2-plex netcamlbox netmulticore rpc-auth-local \
		netstring-pcre
OCAML_LDLIBS=	${OCAML_PKGDIRS:S/^/${OCAML_SITELIBDIR}\//}

OPTIONS_DEFINE=	SSL NETHTTPD AUTH_DH GTK2 APACHE ZIP SCRAM EXAMPLES DOCS
OPTIONS_DEFAULT=SSL
AUTH_DH_DESC=	Diffie-Hellman authorization support
NETHTTPD_DESC=	Integrated HTTP daemon
SCRAM_DESC=	SCRAM support
ZIP_DESC=	Compression support
APACHE_DESC=	Apache mod connector (experimental)

CONFIGURE_ARGS+=-disable-gtk \
		-enable-pcre

SSL_BUILD_DEPENDS=	${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
SSL_RUN_DEPENDS=	${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl

AUTH_DH_BUILD_DEPENDS=	${SA_DIR}/cryptgps/cryptgps.a:${PORTSDIR}/security/ocaml-cryptgps
AUTH_DH_RUN_DEPENDS=	${SA_DIR}/cryptgps/cryptgps.a:${PORTSDIR}/security/ocaml-cryptgps

GTK2_BUILD_DEPENDS=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
GTK2_RUN_DEPENDS=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2

ZIP_BUILD_DEPENDS=	${SA_DIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip
ZIP_RUN_DEPENDS=	${SA_DIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip

SCRAM_BUILD_DEPENDS=	${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit
SCRAM_RUN_DEPENDS=	${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	-enable-ssl
OCAML_PKGDIRS+=		equeue-ssl rpc-ssl
.endif

.if ${PORT_OPTIONS:MNETHTTPD}
CONFIGURE_ARGS+=	-with-nethttpd
OCAML_PKGDIRS+=		nethttpd nethttpd-for-netcgi2
.endif

.if ${PORT_OPTIONS:MAUTH_DH}
CONFIGURE_ARGS+=	-with-rpc-auth-dh
OCAML_PKGDIRS+=		rpc-auth-dh
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	-enable-gtk2
OCAML_PKGDIRS+=		equeue-gtk2
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=		22+
CONFIGURE_ARGS+=	-enable-apache -apxs ${APXS} -apache ${HTTPD}
OCAML_PKGDIRS+=		netcgi_apache
.endif

.if ${PORT_OPTIONS:MZIP}
CONFIGURE_ARGS+=	-enable-zip
OCAML_PKGDIRS+=		netzip
.endif

.if ${PORT_OPTIONS:MSCRAM}
CONFIGURE_ARGS+=	-enable-crypto
OCAML_PKGDIRS+=		netmech-scram
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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@(cd ${WRKSRC}/examples/ && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
