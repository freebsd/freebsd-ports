# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	figlet
PORTVERSION=	2.2.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/ \
		LOCAL/obrien

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SysV banner-like program prints strings in large fancy ASCII art

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ENV=	datadir=${DATADIR} prefix=${PREFIX}
MAKE_ARGS=	LD=${CC}
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/figlet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/chkfont ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/figlist ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/showfigfonts ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fonts/*.flf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.flc ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/*.6 ${STAGEDIR}${MANPREFIX}/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/figfont.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
