# New ports collection makefile for:	jade
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	jade
PORTVERSION=	1.2.1
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/

PATCH_SITES=	http://ftp.debian.org/debian/pool/main/j/jade/
PATCHFILES=	jade_1.2.1-35.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	An object-oriented SGML/XML parser toolkit and DSSSL engine

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

post-extract:
	@${CHMOD} u+w ${WRKSRC}/configure

pre-install:
	@${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) \
		-exec ${RM} -f \{} \;

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	${STRIP_CMD} ${PREFIX}/bin/$i
.endfor
	${MKDIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${MKDIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${PREFIX}/share/doc/jade
	${MKDIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${PORTNAME}/catalog

.include <bsd.port.mk>
