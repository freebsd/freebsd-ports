# ex:ts=8
# Ports collection makefile for:  icb
# Date created:			  Tue Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	icb
PORTVERSION=	5.1.0
PORTREVISION=	3
CATEGORIES=	net tcl84
MASTER_SITES=	http://www.obfuscation.org/ftp/pub/icb/ \
		ftp://ftp.obfuscation.org/pub/icb/
DISTNAME=	c${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet CB - a mostly-defunct chat client

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclinclude=${LOCALBASE}/include/tcl8.4 \
		--with-tcllib=${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/icb
	${INSTALL_DATA} ${WRKSRC}/icbserverdb ${PREFIX}/share/icb
.for file in bartender confuse echofunctions sample.icbrc
	${INSTALL_DATA} ${WRKSRC}/contrib/${file} ${PREFIX}/share/icb
.endfor

.include <bsd.port.mk>
