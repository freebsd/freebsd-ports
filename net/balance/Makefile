# New ports collection makefile for:	balance
# Date created:				Wed 6 Dec 2000
# Whom:					Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	balance
PORTVERSION=	3.24
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/ \
		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	balance

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Simple but powerful generic tcp proxy with round robin features

ALL_TARGET=	balance
USE_REINPLACE=	yes
USE_RC_SUBR=	yes

MAN1=		balance.1

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|' \
	-e 's|^CC|CC?|' ${WRKSRC}/Makefile
post-build:
	@${SED} -e 's,%%RC_SUBR%%,${RC_SUBR},g' -e 's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/balance ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/balance.1 ${PREFIX}/man/man1
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	@${MKDIR} /var/run/balance

.include <bsd.port.mk>
