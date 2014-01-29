# Created by: ijliao
# $FreeBSD$

PORTNAME=	csv2latex
PORTVERSION=	0.18
PORTEPOCH=	1
CATEGORIES=	textproc converters
MASTER_SITES=	http://ftp.debian.org/pool/main/c/csv2latex/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Converts a well formed csv file to a LaTeX document

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/csv2latex

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.if ( defined(WITH_MAN) &&  !defined(NO_INSTALL_MANPAGES) )
BUILD_DEPENDS +=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
PLIST_FILES+=	man/man1/${PORTNAME}.1.gz

post-build:
	docbook-to-man ${WRKSRC}/${PORTNAME}.sgml > ${WRKSRC}/${PORTNAME}.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.endif

.include <bsd.port.mk>
