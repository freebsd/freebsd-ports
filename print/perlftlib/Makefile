# New ports collection makefile for:	perlftlib
# Date created:		98/12/22
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	perlftlib
PORTVERSION=	1.2
CATEGORIES=	print perl5
MASTER_SITES=	http://www.io.com/~kazushi/xtt/ \
		${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Libraries to use the FreeType library from the perl language

RUN_DEPENDS=	${SITE_PERL}/jcode.pl:${PORTSDIR}/japanese/jcode.pl

USE_FREETYPE=	yes
USE_PERL5=	yes
NOMANCOMPRESS=	yes
MAN1=		mkttfdir.1 ftinfo.1
MAN3=		FreeType.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAKE_ENV=	PERL_VER=${PERL_VER} PERL5=${PERL5}

pre-patch:
	@${PERL} -pi -e 's!/usr/local/X11R6.3!${PREFIX}!' ${WRKSRC}/FreeType/Makefile.PL

post-build:
.for DIST in ftinfo mkttfdir
	@${PERL} -pi -e 's;^#! */usr/local/bin/perl *;#!${PERL5};' ${WRKSRC}/${DIST}
.endfor

.include <bsd.port.mk>
