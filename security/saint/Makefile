# New ports collection makefile for:	SAINT
# Date created:		27 Jan 2000
# Whom:			Carl Johan Madestrand <calle.madestrand@norrgarden.se>
#
# $FreeBSD$
#

PORTNAME=	saint
PORTVERSION=	2.1.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.wwdsi.com/pub/saint/			\
		http://www.wwdsi.com/saint/downloads/		\
		ftp://ukug.uk.freebsd.org/pub/lord_cj/

MAINTAINER=	cj@vallcom.net

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USE_PERL5=	yes
MAKE_ENV=	XFLAGS="DAUTH_GID_T=int -DSYS_ERRLIST_DECLARED -DFDSETSIZE=2048"
ALL_TARGET=	freebsd
INSTALL_TARGET=	all

pre-configure:
		@ cd ${WRKSRC}; ${SETENV} ${PERL5} ${WRKSRC}/reconfig

pre-install:
		${MKDIR} ${PREFIX}/saint
		${TAR} --directory ${WRKSRC} -cf - . --exclude src --exclude Makefile | \
			${TAR} --directory ${PREFIX}/saint -xf -

.include <bsd.port.mk>
