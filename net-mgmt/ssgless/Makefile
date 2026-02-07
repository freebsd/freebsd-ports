PORTNAME=	ssgless
PORTVERSION=	1.3
CATEGORIES=	net-mgmt
DISTFILES=

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	View ScreenOS configuration files

LICENSE=	BSD2CLAUSE

LESS=	`whereis -bq less`

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME} bin/lesspipe-ssg.awk

SUB_FILES=	${PORTNAME} lesspipe-ssg.awk

SUB_LIST=	"AWK=${AWK}" "LESS=${LESS}"

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/lesspipe-ssg.awk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
