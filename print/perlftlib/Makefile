# New ports collection makefile for:	perlftlib
# Version required:	1.2
# Date created:		98/12/22
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	perlftlib-1.2
CATEGORIES=	print perl5
MASTER_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/ft/ \
		http://WWW.FreeBSD.ORG/~sada/distfiles/ \
		http://WWW.jp.FreeBSD.ORG/~sada/distfiles/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype
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
