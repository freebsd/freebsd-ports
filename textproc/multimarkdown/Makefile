# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multimarkdown
PORTVERSION=	3.7.1
PORTREVISION=	2
DISTNAME=	peg-${PORTNAME}-${PORTVERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/fletcher/peg-${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C

CONFLICTS_INSTALL=	mtools-*

LICENSE=	MIT

FETCH_ARGS=	-Fpr

USE_GMAKE=	yes
ALL_TARGET=	ALL

post-patch:
	@${REINPLACE_CMD} -E "/CFLAGS/s/-arch [[:alnum:]]+//; /CFLAGS/s/\?=/\+=/; \
		s/CC=gcc//" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/multimarkdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
