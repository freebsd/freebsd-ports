# Created by: Pavel I Volkov
# $FreeBSD$

PORTNAME=	ssgless
PORTVERSION=	1.2
CATEGORIES=	net-mgmt
DISTFILES=

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	View ScreenOS configuration files

LICENSE=	BSD

LESS=	`whereis -bq less`

NOFETCHFILES=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_MTREE=	yes

PLIST_FILES=	bin/${PORTNAME} bin/lesspipe-ssg.awk

SUB_FILES=	${PORTNAME} lesspipe-ssg.awk

SUB_LIST=	"AWK=${AWK}" "LESS=${LESS}"

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/lesspipe-ssg.awk ${PREFIX}/bin

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
