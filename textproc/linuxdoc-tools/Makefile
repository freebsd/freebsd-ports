PORTNAME=	linuxdoc-tools
DISTVERSION=	0.9.83
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Fork of SGML-tools specially tailored for linuxdoc SGMLs
WWW=		https://gitlab.com/agmartin/linuxdoc-tools

LICENSE=	GPLv3 LinuxdocTools
LICENSE_COMB=	multi
LICENSE_NAME_LinuxdocTools=	The linuxdoc-tools license
LICENSE_FILE_LinuxdocTools=	${WRKSRC}/COPYING
LICENSE_PERMS_LinuxdocTools=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	gawk:lang/gawk \
		nsgmls:textproc/jade \
		sgmlsasp:textproc/sgmls
RUN_DEPENDS=	gawk:lang/gawk \
		nsgmls:textproc/jade \
		sgmlsasp:textproc/sgmls

USE_GITLAB=	yes
GL_ACCOUNT=	agmartin

GNU_CONFIGURE=	yes
USES=		gmake groff:both perl5 tar:bzip2
CONFIGURE_ARGS=	--with-installed-sgmlsasp

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	bash:shells/bash
DOCS_USES=		makeinfo tex
DOCS_USE=		TEX=dvipsk:build,latex:build,pdftex:build
DOCS_CONFIGURE_ENABLE=	docs

.include <bsd.port.mk>
