# $FreeBSD$

PORTNAME=	ifmail
PORTVERSION=	2.15
PORTREVISION=	5
CATEGORIES=	news comms
MASTER_SITES=	SUNSITE/system/fido

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FidoNet(tm) support package for UN*X platform

USERS=		ifmail
CFLAGS+=	-DHAS_STDARG_H -Wall
GID!=		id -g
MAKE_ARGS=	OWNER=${UID} CC="${CC}" GROUP=${GID} CFLAGS="${CFLAGS}"

LMAN3=		parsedate.3
LMAN8=		ifmail.8 iftoss.8

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/ifmail

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/ifmail/*
.for i in ${LMAN8}
	${INSTALL_MAN} ${WRKSRC}/ifgate/${i} ${STAGEDIR}${PREFIX}/man/man8/
.endfor
.for i in ${LMAN3}
	${INSTALL_MAN} ${WRKSRC}/iflib/${i} ${STAGEDIR}${PREFIX}/man/man3/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.for i in ifcico ifgate iflib
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${STAGEDIR}${DOCSDIR}/README.${i}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/misc -cf - . | ${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
