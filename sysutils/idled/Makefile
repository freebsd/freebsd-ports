# New ports collection makefile for:	idled
# Date created:			12 March 1997
# Whom:		Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	idled
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.darkwing.com/idled/download/	\
		ftp://ftp.cs.hope.edu/pub/idled/

MAINTAINER=	andrew@ugh.net.au
COMMENT=	A daemon that logs out idle users and those users hogging resources

NO_CDROM=	non-profit use and distribution only
MANCOMPRESSED=	yes
MAN5=		idled.cf.5
MAN8=		idled.8

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g'

USE_RC_SUBR=	yes
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
SED_SCRIPT+=	-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'
PLIST_SUB+=     RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

post-extract:
	(cd ${WRKSRC}; make clean)

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/idled.sh >${WRKDIR}/idled.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/idled.sh ${RC_DIR}/idled${RC_SUFX}
	@${STRIP_CMD} ${PREFIX}/libexec/idled

.include <bsd.port.mk>
