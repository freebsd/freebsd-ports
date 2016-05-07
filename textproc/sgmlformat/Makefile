# Created by: jfieber
# $FreeBSD$

PORTNAME=	sgmlformat
PORTVERSION=	1.7
PORTREVISION=	6
CATEGORIES=	textproc print
MASTER_SITES=	LOCAL/kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Generates groff and HTML from linuxdoc and docbook SGML documents

USES=		perl5 uidfix
USE_PERL5=	run
MAKE_ENV=	STAGEDIR=${STAGEDIR}

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred.

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != "i386"
WITH_OPENJADE=	yes
.endif

.if defined(WITH_OPENJADE)
RUN_DEPENDS=	openjade>0:textproc/openjade
.else
RUN_DEPENDS=	nsgmls:textproc/jade
.endif
RUN_DEPENDS+=	linuxdoc>0:textproc/linuxdoc \
		docbook-sgml>0:textproc/docbook-sgml

.if defined(WITH_OPENJADE)
post-patch:
	@${REINPLACE_CMD} -e 's,nsgmls,onsgmls,g' ${WRKSRC}/sgmlfmt/sgmlfmt.pl
	@${REINPLACE_CMD} -e 's,nsgmls,onsgmls,g' ${WRKSRC}/instant/traninit.c
.endif

post-build:
	${REINPLACE_CMD} -E 's#(/usr|${PREFIX})/bin/perl#${PERL}#' ${WRKSRC}/sgmlfmt/sgmlfmt

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sgml/transpec

.include <bsd.port.post.mk>
