# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	p11-kit
PORTVERSION=	0.23.21
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/p11-glue/p11-kit/releases/download/${PORTVERSION}/

# Partially backport https://github.com/p11-glue/p11-kit/pull/315
PATCH_SITES=	https://github.com/p11-glue/p11-kit/commit/
PATCHFILES=	1a21df391691d9a9c7b5ebc77022385f7feb266b.patch:-p1

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
LIB_DEPENDS=	libtasn1.so:security/libtasn1 \
		libffi.so:devel/libffi

USES=		localbase meson pkgconfig tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Dlibffi=enabled -Dtrust_module=enabled \
		-Dtrust_paths=${LOCALBASE}/share/certs/ca-root-nss.crt \
		-Dnls=false

OPTIONS_DEFINE=	BASH DOCS MANPAGES TEST
OPTIONS_SUB=	yes
MANPAGES_IMPLIES=	DOCS
OPTIONS_DEFAULT=	BASH MANPAGES

BASH_BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion
BASH_RUN_DEPENDS=	bash-completion>=0:shells/bash-completion
BASH_MESON_ENABLED=	bash_completion

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_USES=		gnome
DOCS_USE=		GNOME=glib20
DOCS_MESON_TRUE=	gtk_doc

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man

TEST_MESON_TRUE=	test

# Partially backport https://github.com/p11-glue/p11-kit/pull/315
pre-configure:
	${MV} ${WRKSRC}/trust/trust-extract-compat.in ${WRKSRC}/trust/trust-extract-compat

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${PREFIX}/etc/pkcs11/pkcs11.conf.example ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/pkcs11

.include <bsd.port.mk>
