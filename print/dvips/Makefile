# New ports collection makefile for:    dvips
# Version required:     5.58
# Date created:         30 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.11 1996/09/16 00:56:17 asami Exp $
#

DISTNAME=	dvips
PKGNAME=	dvips-5.58
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/dviware/dvips/
DISTFILES=	dvips558.tar.gz

MAINTAINER=	jmz@FreeBSD.org

IS_INTERACTIVE=	yes

EXTRACT_CMD=	(zcat | dd 2>/dev/null | tar xf -)
EXTRACT_ARGS=	<

pre-install:
	@${MKDIR} ${PREFIX}/lib/texmf

pre-clean:
	@rm -f ${SCRIPTDIR}/post-install

.include <bsd.port.mk>
