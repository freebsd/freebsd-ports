# New ports collection makefile for:	perlftlib
# Date created:		98/12/22
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	perlftlib
PORTVERSION=	1.2
CATEGORIES=	print perl5
MASTER_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/ft/ \
		${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada

MAINTAINER=	taoka@FreeBSD.org

LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype
RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/jcode.pl:${PORTSDIR}/japanese/p5-jcode.pl

USE_PERL5=	yes
NOMANCOMPRESS=	yes
MAN1=		mkttfdir.1 ftinfo.1

MAKE_ENV=	PERL_VER=${PERL_VER} PERL5=${PERL5}

pre-patch:
	${MV} ${WRKSRC}/FreeType/Makefile.PL ${WRKSRC}/FreeType/Makefile.PL.bak
	${SED} 's,/usr/local/X11R6.3,${PREFIX},' \
		${WRKSRC}/FreeType/Makefile.PL.bak \
		> ${WRKSRC}/FreeType/Makefile.PL

post-build:
		cd ${WRKSRC}; \
		for DIST in ftinfo mkttfdir; do \
			${MV} $${DIST} $${DIST}.bak; \
			${SED} -e 's;^#! */usr/local/bin/perl *;#!${PERL5};' \
				$${DIST}.bak > $${DIST}; \
		done

.include <bsd.port.mk>
