# Ports collection makefile for:  amap
# Date created:			  23 Mar  2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	amap
PORTVERSION=	5.2
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	onatan@gmail.com
COMMENT=	Application mapper

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_OPENSSL=	yes

MAN1=		amap.1
.if !defined(NOPORTDOCS)
PORTDOCS=	README TODO CHANGES AMAP-LIB-INTERFACE
.endif
PLIST_SUB=	AMAPLIBDIR=lib/${PORTNAME} AMAPINCDIR=include/${PORTNAME}

CONF_DIR=	${PREFIX}/etc/${PORTNAME}
LOCAL_CONF_FILES=	appdefs.resp appdefs.rpc appdefs.trig

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	CONF_FILES="${LOCAL_CONF_FILES}" CONF_DIR="${CONF_DIR}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g; \
		 s|\(-DAMAP_PREFIX\)=\(\$$PREFIX\)|\1=\\\\\\"\2\\\\\\"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|; s|^CC=.*||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|etc/|etc/amap/|g' ${WRKSRC}/amap-lib.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/amap ${PREFIX}/bin/amap6
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/amap-lib.o ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/include/${PORTNAME}
.	for i in amap.h amap-inc.h amap-lib.h
		${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/include/${PORTNAME}
.	endfor
	${MKDIR} ${CONF_DIR}
.	for i in ${LOCAL_CONF_FILES}
		${INSTALL_DATA} ${WRKSRC}/${i} ${CONF_DIR}/${i}.default
.	endfor
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${MANPREFIX}/man/man1
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.		for i in ${PORTDOCS}
			${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
