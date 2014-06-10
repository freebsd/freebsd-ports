# Created by: Brian Candler <B.Candler@pobox.com>
# $FreeBSD$

PORTNAME=	docbook-utils
PORTVERSION=	0.6.14
PORTREVISION=	13
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	docbook-tools/new-trials/SOURCES

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Generates various output formats from DocBook SGML documents

BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular \
		nsgmls:${PORTSDIR}/textproc/jade
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular \
		nsgmls:${PORTSDIR}/textproc/jade \
		sgmlspl:${PORTSDIR}/textproc/p5-SGMLSpm \
		lynx:${PORTSDIR}/www/lynx

CONFLICTS=	docbook2X-*

USES=		perl5 gmake shebangfix
USE_PERL5=	run
USE_TEX=	jadetex
GNU_CONFIGURE=	yes
MAKE_ARGS+=	docdir="${DOCSDIR}" htmldir="${DOCSDIR}/html"
SHEBANG_FILES=	bin/sgmldiff.in
perl_OLD_CMD=	@perl_bindir@/perl

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/sgml/catalog|${PREFIX}/share/sgml/catalog|g' \
		${WRKSRC}/doc/HTML/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/sgml|${LOCALBASE}/share/sgml|g' \
			-e 's|/usr/bin/|${LOCALBASE}/bin/|g' \
			${WRKSRC}/doc/refentry/*.sgml \
			${WRKSRC}/backends/txt

pre-configure:
	${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
