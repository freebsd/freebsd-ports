# New ports collection makefile for:	mailfront
# Date created:		03 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	mailfront
PORTVERSION=	0.88
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/mailfront/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Mail server network protocol front-ends

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg-unix.a:${PORTSDIR}/devel/bglibs

QMAIL_ROOT?=	/var/qmail

DOCS=		NEWS README TODO *.html

pre-build:
	${ECHO_CMD} "${LOCALBASE}/include/bglibs" > ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${LOCALBASE}/lib"		> ${WRKSRC}/conf-bglibs
	${ECHO_CMD} "${PREFIX}/bin"		> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"		> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${QMAIL_ROOT}"		> ${WRKSRC}/conf-qmail

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
