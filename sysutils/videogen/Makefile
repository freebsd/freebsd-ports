# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	videogen
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.dynaweb.hu/opensource/videogen/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for calculating XFree86 modelines

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/videogen man/man1/videogen.1.gz
PORTDOCS=	BUGS CHANGES README THANKS
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1x ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}.conf

.include <bsd.port.mk>
