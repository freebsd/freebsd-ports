# Created by: Timothy Redaelli <drizzt@gufi.org>
# $FreeBSD$

PORTNAME=	netselect
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://apenwarr.ca/netselect/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultrafast implementation of ping

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	SUID DOCS
OPTIONS_SUB=	yes
SUID_DESC=	Install with the setuid bit to allow use by non-root users
EXTRACT_AFTER_ARGS=netselect/netselect.c netselect/README

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${REINPLACE_CMD} -E -i "" -e 's|[[:blank:]]+$$||' ${WRKSRC}/README

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
