# Created by: Stephane Legrand <stephane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	net
PORTVERSION=	4.0.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml modules for Internet applications

LICENSE=	GPLv2

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:devel/ocaml-pcre
RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:devel/ocaml-pcre

CONFLICTS=	ocaml-equeue-2* ocaml-netclient-0*

USES=			gmake
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-disable-gtk \
			-enable-pcre

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
		netstring-pcre netunidata
OCAML_LDLIBS=	${OCAML_PKGDIRS:S/^/${OCAML_SITELIBDIR}\//}

OPTIONS_DEFINE=	NETHTTPD GTK2 GNUTLS APACHE ZIP EXAMPLES DOCS
OPTIONS_DEFAULT=GNUTLS
NETHTTPD_DESC=	Integrated HTTP daemon
ZIP_DESC=	Compression support
APACHE_DESC=	Apache mod connector (experimental)
GNUTLS_DESC=	SSL/TLS support via GnuTLS

GTK2_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
GTK2_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
ZIP_BUILD_DEPENDS=	${SA_DIR}/zip/zip.a:archivers/ocaml-zip
ZIP_RUN_DEPENDS=	${SA_DIR}/zip/zip.a:archivers/ocaml-zip
NETHTTPD_CONFIGURE_ON=	-with-nethttpd
NETHTTPD_VARS=		OCAML_PKGDIRS+=nethttpd
GTK2_CONFIGURE_ON=	-enable-gtk2
GTK2_VARS=		OCAML_PKGDIRS+=equeue-gtk2
GNUTLS_USES=		pkgconfig
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	-enable-gnutls
GNUTLS_VARS=		OCAML_PKGDIRS+=nettls-gnutls
APACHE_BROKEN=		does not build with APACHE option enabled
APACHE_USE=		APACHE=22+
APACHE_CONFIGURE_ON=	-enable-apache -apxs ${APXS} -apache ${HTTPD}
APACHE_VARS=		OCAML_PKGDIRS+=netcgi2-apache
ZIP_CONFIGURE_ON=	-enable-zip
ZIP_VARS=		OCAML_PKGDIRS+=netzip

post-patch:
	@${REINPLACE_CMD} -e 's/camlzip/zip/' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@(cd ${WRKSRC}/examples/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
