# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	linuxdoc-tools
PORTVERSION=	0.9.77
CATEGORIES=	textproc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	felix@palmen-it.de
COMMENT=	Fork of SGML-tools specially tailored for linuxdoc SGMLs

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

GNU_CONFIGURE=	yes
USES=		gmake groff:both perl5
CONFIGURE_ARGS=	--with-installed-sgmlsasp

PORTDOCS=	*
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	bash:shells/bash
DOCS_USE=		tex=latex:build tex=pdftex:build tex=dvipsk:build
DOCS_USES=		makeinfo
DOCS_CONFIGURE_ENABLE=	docs

.include <bsd.port.mk>
