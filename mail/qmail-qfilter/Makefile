# New ports collection makefile for:	qmail-qfilter
# Date created:		2004-10-13
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qmail-qfilter
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Front-end for qmail-queue to run messages through filters

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg.a:${PORTSDIR}/devel/bglibs

USE_GPG=	yes
SIG_SUFFIX=	.sig
LDFLAGS?=	-s

MAN1=		qmail-qfilter.1
DOCS=		NEWS README TODO

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${LOCALBASE}/lib"	> ${WRKSRC}/conf-bglibs
	${ECHO_CMD} "${LOCALBASE}/include/bglibs" > ${WRKSRC}/conf-bgincs

do-install:
	cd ${WRKSRC} && ./installer
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} samples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
