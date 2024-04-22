PORTNAME=	clog
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	LOCAL/obrien

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcp connection logger daemon

PATCH_DEPENDS=	rcsdiff:devel/rcs

WRKSRC=		${WRKDIR}/clog
ALL_TARGET=	freebsd

post-patch:
	@${REINPLACE_CMD} -e 's,gcc,$${CC},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clog ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/clog.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
