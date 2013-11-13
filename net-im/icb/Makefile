# Created by: David O'Brien (obrien@NUXI.ucdavis.edu)
# $FreeBSD$

PORTNAME=	icb
PORTVERSION=	5.1.0
PORTREVISION=	4
CATEGORIES=	net-im tcl
#MASTER_SITES=	http://www.obfuscation.org/icb/
MASTER_SITES=	http://fossies.org/linux/misc/old/
DISTNAME=	c${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet CB - a mostly-defunct chat client

USES=		readline tk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tcllib=${LOCALBASE}/lib

PORTEXAMPLES=	bartender confuse echofunctions sample.icbrc
PLIST_FILES=	bin/icb %%DATADIR%%/icbserverdb
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/icbserverdb ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
