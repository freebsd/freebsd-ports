# New ports collection makefile for:	sformat
# Date created:				16 December 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	sformat
PORTVERSION=	3.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/ \
		ftp://ftp.berlios.de/pub/sformat/

MAINTAINER=	marius@alchemy.franken.de

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		sformat.1

MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG"

post-extract:
.if ${MACHINE_ARCH} != "i386"
	@${LN} -s ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-cc.rul
.endif

post-patch:
.for i in datio.c sformat.1
	@${REINPLACE_CMD} -i "" -e 's:%%DATADIR%%:${DATADIR}:g;' \
		${WRKSRC}/sformat/${i}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sformat/OBJ/${ARCH}-freebsd-cc/sformat \
		${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sformat/sformat.dat ${DATADIR}
	@${INSTALL_MAN} ${WRKSRC}/sformat/sformat.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
