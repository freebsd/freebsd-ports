# ex:ts=8
# Ports collection makefile for:  icb
# Date created:			  Tue Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	icb
PORTVERSION=	5.1.0
PORTREVISION=	4
CATEGORIES=	net-im tcl
MASTER_SITES=	http://www.obfuscation.org/icb/
DISTNAME=	c${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet CB - a mostly-defunct chat client

USE_TK_BUILD=	yes
USE_TK=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tcllib=${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

PORTEXAMPLES=	bartender confuse echofunctions sample.icbrc
PLIST_FILES=	bin/icb %%DATADIR%%/icbserverdb
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/icbserverdb ${DATADIR}
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
