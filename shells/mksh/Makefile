# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mksh
PORTVERSION=	54
DISTVERSIONPREFIX=	R
CATEGORIES=	shells
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/mir/mksh/ \
		http://pub.allbsd.org/MirOS/dist/mir/mksh/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	MirBSD Korn Shell

LICENSE=	BSD3CLAUSE ISCL ML PD
LICENSE_COMB=	multi
LICENSE_NAME_ML=	MirOS License
LICENSE_PERMS_ML=	${_LICENSE_LIST_PERMS}
LICENSE_GROUPS_ML=	OSI
LICENSE_TEXT_ML=	Please, read it contains from https://www.mirbsd.org/LICENCE

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} SHELL=${SH} ${SH} ${WRKSRC}/Build.sh -r -c lto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
