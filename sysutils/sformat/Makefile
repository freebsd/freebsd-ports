# New ports collection makefile for:	sformat
# Date created:				16 December 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	sformat
PORTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/ \
		ftp://ftp.berlios.de/pub/sformat/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Allows formatting/partitioning/analysis/repairing of SCSI disks

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		sformat.1

MAKE_ENV=	CCOM=${CC}
SFMTTARGET=	${ARCH}-freebsd-${CC}

.include <bsd.port.pre.mk>

post-extract:
.for i in config.guess config.sub
	@${CP} ${PORTSDIR}/Templates/${i} ${WRKSRC}/conf
.endfor
.if ${ARCH} != "i386" || ${CC} != "cc"
	@${LN} -sf ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${SFMTTARGET}.rul
.endif

post-patch:
.for i in datio.c sformat.1
	@${REINPLACE_CMD} -i "" -e 's:%%DATADIR%%:${DATADIR}:g;' \
		${WRKSRC}/sformat/${i}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sformat/OBJ/${SFMTTARGET}/sformat \
		${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sformat/sformat.dat ${DATADIR}
	@${INSTALL_MAN} ${WRKSRC}/sformat/sformat.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
