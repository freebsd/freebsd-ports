# New ports collection makefile for:	mailfront
# Date created:		03 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	mailfront
PORTVERSION=	0.92
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Mail server network protocol front-ends

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg.a:${PORTSDIR}/devel/bglibs \
		${LOCALBASE}/lib/libcvm-client.a:${PORTSDIR}/security/cvm

QMAIL_ROOT?=	/var/qmail
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS?=	-s

DOCS=		NEWS README TODO *.html

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${LOCALBASE}/include/bglibs" > ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${LOCALBASE}/lib"	> ${WRKSRC}/conf-bglibs
	${ECHO_CMD} "${QMAIL_ROOT}"	> ${WRKSRC}/conf-qmail

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
