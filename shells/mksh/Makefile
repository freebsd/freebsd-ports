# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mksh
PORTVERSION=	59b
DISTVERSIONPREFIX=	R
CATEGORIES=	shells
MASTER_SITES=	https://www.mirbsd.org/MirOS/dist/mir/mksh/ \
		https://pub.allbsd.org/MirOS/dist/mir/mksh/

MAINTAINER=	schaiba@gmail.com
COMMENT=	MirBSD Korn Shell

LICENSE=	ISCL ML
LICENSE_COMB=	multi
LICENSE_GROUPS_ML=	OSI
LICENSE_NAME_ML=	MirOS
LICENSE_TEXT_ML=	Please, read its contents from http://www.mirbsd.org/TaC-mksh.txt
LICENSE_PERMS_ML=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} SHELL=${SH} ${SH} ${WRKSRC}/Build.sh -r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
