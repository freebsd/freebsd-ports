# New ports collection makefile for:	cvm
# Date created:		2003-12-24
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvm
PORTVERSION=	0.32
CATEGORIES=	security
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Credential Validation Modules

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg-unix.a:${PORTSDIR}/devel/bglibs

CONFLICTS=	bglibs-1.00*

LDFLAGS?=	-s

DOCS=		NEWS README TODO *.html

do-configure:
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${LOCALBASE}/include/bglibs" > ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${LOCALBASE}/lib"	> ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
