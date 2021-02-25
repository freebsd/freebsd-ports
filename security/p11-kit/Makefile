# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	p11-kit
DISTVERSION=	0.23.22
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/p11-glue/p11-kit/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/p11-glue/p11-kit/commit/
PATCHFILES=	507c394cfcf4edffc5e4450c5d737e545c26b857.patch:-p1

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		bash-completion>=0:shells/bash-completion
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
LIB_DEPENDS=	libffi.so:devel/libffi \
		libtasn1.so:security/libtasn1

USES=		localbase meson pkgconfig tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbash_completion=enabled \
		-Dlibffi=enabled \
		-Dnls=false \
		-Dtrust_module=enabled \
		-Dtrust_paths=${LOCALBASE}/share/certs/ca-root-nss.crt

OPTIONS_DEFINE=		DOCS MANPAGES TEST
OPTIONS_SUB=		yes
MANPAGES_IMPLIES=	DOCS
OPTIONS_DEFAULT=	MANPAGES

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_USES=		gnome
DOCS_USE=		GNOME=glib20
DOCS_MESON_TRUE=	gtk_doc

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man

TEST_MESON_TRUE=	test

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${PREFIX}/etc/pkcs11/pkcs11.conf.example ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/pkcs11

.include <bsd.port.mk>
