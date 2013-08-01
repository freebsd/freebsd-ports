# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	figlet
PORTVERSION=	2.2.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	SysV banner-like program prints strings in large fancy ASCII art

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ENV=	datadir=${DATADIR} prefix=${PREFIX}
MAKE_ARGS=	LD=${CC}

MAN6=		chkfont.6 figlet.6 figlist.6 showfigfonts.6

regression-test:
	@ cd ${WRKSRC} && ${MAKE} check

post-build tests test: regression-test

do-install:
	@ ${MKDIR} ${DATADIR}
	@ ${INSTALL_PROGRAM} ${WRKSRC}/figlet ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/chkfont ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/figlist ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/showfigfonts ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/fonts/*.flf ${DATADIR}
	@ ${INSTALL_DATA} ${WRKSRC}/fonts/*.flc ${DATADIR}
	@ cd ${WRKSRC} && ${INSTALL_MAN} *.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/figfont.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
