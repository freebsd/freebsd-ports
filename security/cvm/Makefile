# New ports collection makefile for:	cvm
# Date created:		2003-12-24
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvm
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Credential Validation Modules

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool15
LIB_DEPENDS=	bg.1:${PORTSDIR}/devel/bglibs

CONFLICTS=	bglibs-1.00*

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_LDCONFIG=	yes
LDFLAGS?=	-s
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

DOCS=		NEWS README TODO *.html

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

.include <bsd.port.mk>
