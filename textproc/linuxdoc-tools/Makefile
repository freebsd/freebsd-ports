# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	linuxdoc-tools
PORTVERSION=	0.9.69
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
USES=		gmake perl5
CONFIGURE_ARGS=	--with-installed-sgmlsasp

PORTDOCS=	*
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	bash:shells/bash
DOCS_USES=		makeinfo
DOCS_MAKE_ENV=		LANG=C BUILD_DOCS=true

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/ s|=|?=|' \
		${WRKSRC}/rtf-fix/Makefile

.include <bsd.port.mk>
