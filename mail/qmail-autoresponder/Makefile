# New ports collection makefile for:	qmail-autoresponder
# Date created:		25 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#
# Compile-time options:
# WITH_MYSQL=yes	enable support for MySQL
#

PORTNAME=	qmail-autoresponder
PORTVERSION=	0.96.2
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Rate-limited autoresponder for qmail

BUILD_DEPENDS=	${BGLIBS_LIB}/libbg.a:${PORTSDIR}/devel/bglibs

USE_GPG=	yes
SIG_SUFFIX=	.sig
LDFLAGS?=	-s
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

PROGS=		qmail-autoresponder
MAN1=		qmail-autoresponder.1
DOCS=		NEWS README TODO procedure.txt

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
PROGS+=		qmail-autoresponder-mysql
DOCS+=		schema.mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

ALL_TARGET=	${PROGS}

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"		> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"		> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"		> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"		> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"		> ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGS} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
