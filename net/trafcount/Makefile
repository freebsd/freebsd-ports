# New ports collection makefile for:    trafcount
# Date created:         Sat Jun  2 16:29:22 IDT 2001
# Whom:                 amir@boom.org.il
#
# $FreeBSD$
#

PORTNAME=		trafcount
PORTVERSION=		0.2.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trafcount

MAINTAINER=		amir@boom.org.il

BROKEN=			"Does not compile"

STARTUP=		trafcount.sh
MAN1=			trafcount.1

MAN_COMPRESSED=		no
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's@kmoddir=/modules@kmoddir=${PREFIX}/libexec@g' \
		${WRKSRC}/trafcount.sh
	@${REINPLACE_CMD} -e 's@/usr/local@${PREFIX}@g' \
		${WRKSRC}/client/Makefile ${WRKSRC}/module/Makefile \
		${WRKSRC}/Makefile

.if !exists(/usr/src/sys/Makefile)
BROKEN=			"Kernel source files required"
.endif

.include <bsd.port.mk>
