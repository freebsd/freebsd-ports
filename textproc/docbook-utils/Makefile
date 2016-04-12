# Created by: Brian Candler <B.Candler@pobox.com>
# $FreeBSD$

PORTNAME=	docbook-utils
PORTVERSION=	0.6.14
PORTREVISION=	13
CATEGORIES=	textproc
MASTER_SITES=	SOURCEWARE/docbook-tools/new-trials/SOURCES

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Generates various output formats from DocBook SGML documents

BUILD_DEPENDS+=	docbook-sgml>0:textproc/docbook-sgml \
		dsssl-docbook-modular>0:textproc/dsssl-docbook-modular \
		nsgmls:textproc/jade
RUN_DEPENDS+=	dsssl-docbook-modular>0:textproc/dsssl-docbook-modular \
		nsgmls:textproc/jade \
		sgmlspl:textproc/p5-SGMLSpm \
		lynx:www/lynx

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
