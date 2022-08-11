PORTNAME=	netselect
PORTVERSION=	0.4
DISTVERSIONPREFIX=${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultrafast implementation of ping

LICENSE=	BSD3CLAUSE

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	apenwarr

OPTIONS_DEFINE=	SUID DOCS
OPTIONS_SUB=	yes
SUID_DESC=	Install with the setuid bit to allow use by non-root users

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${REINPLACE_CMD} -E -i "" -e 's|[[:blank:]]+$$||' ${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
