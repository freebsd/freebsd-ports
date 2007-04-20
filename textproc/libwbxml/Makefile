# New ports collection makefile for:	libwbxml
# Date created:				19 April 2007
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwbxml
PORTVERSION=	0.9.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wbxmllib
DISTNAME=	wbxml2-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Library and tools to parse, encode and handle WBXML documents

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:19 autoconf:259 autoheader:259 automake:19 libtool:15
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

patch-autotools:
	@${CP} ${LOCALBASE}/share/libtool/ltmain.sh ${WRKSRC}/ltmain.sh
	@${CAT} ${LOCALBASE}/share/aclocal/libtool.m4 >> ${WRKSRC}/aclocal.m4
	@${TOUCH} ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} 's|^.*install_prog.*instname.*destdir.*$$||' ${WRKSRC}/ltmain.sh

.include <bsd.port.mk>
