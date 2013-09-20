# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	qmail-autoresponder
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rate-limited autoresponder for qmail

LIB_DEPENDS=	bg-sysdeps.2:${PORTSDIR}/devel/bglibs

USE_MYSQL=	yes

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/bglibs
LDFLAGS+=	-L${LOCALBASE}/lib/mysql -L${LOCALBASE}/lib/bglibs

PROGS=		qmail-autoresponder qmail-autoresponder-mysql
MAN1=		qmail-autoresponder.1
DOCS=		NEWS README TODO procedure.txt schema.mysql

ALL_TARGET=	${PROGS}

NO_STAGE=	yes
do-configure:
	${ECHO_CMD} "${PREFIX}/bin"		> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"		> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"		> ${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGS} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
