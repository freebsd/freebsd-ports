# New ports collection makefile for:    dvips
# Version required:     5.58
# Date created:         30 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.8 1995/04/22 16:49:58 jmz Exp $
#

DISTNAME=	dvips
PKGNAME=	dvips-5.58
CATEGORIES+=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/dviware/dvips/
DISTFILES=	dvips558.tar.gz

MAINTAINER=	jmz@FreeBSD.org

IS_INTERACTIVE=	yes

pre-install:
	@mkdir -p ${PREFIX}/lib/texmf
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
