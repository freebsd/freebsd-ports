# New ports collection makefile for:	cvm
# Date created:		2003-12-24
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvm
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	tarkhil@over.ru
COMMENT=	Credential Validation Modules

LIB_DEPENDS=	bg.2:${PORTSDIR}/devel/bglibs

CONFLICTS=	bglibs-1.00*

USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	#none
USE_LDCONFIG=	yes
LDFLAGS?=	-s
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

DOCS=		NEWS README TODO *.html

OPTIONS=	VCHKPW "Compile cvm-vchkpw" off

.include <bsd.port.pre.mk>

ALL_TARGET=all

.if defined(WITH_VCHKPW)
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
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
