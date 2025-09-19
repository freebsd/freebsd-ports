PORTNAME=	p11-kit
DISTVERSION=	0.25.9
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/p11-glue/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules
WWW=		https://p11-glue.freedesktop.org/p11-kit.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion
LIB_DEPENDS=	libffi.so:devel/libffi \
		libtasn1.so:security/libtasn1

USES=		cpe localbase meson pkgconfig tar:xz
USE_LDCONFIG=	yes

CPE_VENDOR=	p11-kit_project

MESON_ARGS=	-Dnls=false \
		-Dsystemd=disabled \
		-Dzsh_completion=disabled \
		-Dtrust_paths=${DATADIR}/certs

OPTIONS_DEFINE=		DOCS MANPAGES TEST
OPTIONS_SUB=		yes
MANPAGES_IMPLIES=	DOCS
OPTIONS_DEFAULT=	MANPAGES

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man

TEST_MESON_TRUE=	test

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MESON_ARGS+=		-Dglib_prefix=${LOCALBASE}
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${PREFIX}/etc/pkcs11/pkcs11.conf.example ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/pkcs11
	${MKDIR} ${STAGEDIR}${DATADIR}/certs
	${LN} -s /usr/share/certs/trusted ${STAGEDIR}${DATADIR}/certs/anchors
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400024
	${LN} -s /usr/share/certs/blacklisted ${STAGEDIR}${DATADIR}/certs/blocklist
.else
	${LN} -s /usr/share/certs/untrusted ${STAGEDIR}${DATADIR}/certs/blocklist
.endif

.include <bsd.port.mk>
