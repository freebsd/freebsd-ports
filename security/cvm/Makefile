# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvm
PORTVERSION=	0.96
CATEGORIES=	security
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	tarkhil@over.ru
COMMENT=	Credential Validation Modules

LIB_DEPENDS=	bg.2:${PORTSDIR}/devel/bglibs

CONFLICTS=	bglibs-1.00*

USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	#none
USE_LDCONFIG=	yes
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

DOCS=		NEWS README TODO *.html

OPTIONS_DEFINE=	VCHKPW
VCHKPW_DESC=	Compile cvm-vchkpw

NO_STAGE=	yes
.include <bsd.port.options.mk>

ALL_TARGET=all

.if ${PORT_OPTIONS:MVCHKPW}
BUILD_DEPENDS+=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
ALL_TARGET+=	cvm-vchkpw
PLIST_SUB=	VCHKPW=""
.else
PLIST_SUB=	VCHKPW="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libtool|${LIBTOOL}|g' ${WRKSRC}/Makefile

do-configure:
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${PREFIX}/include"	> ${WRKSRC}/conf-include
	${ECHO_CMD} "${PREFIX}/lib"	> ${WRKSRC}/conf-lib
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"       > ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
