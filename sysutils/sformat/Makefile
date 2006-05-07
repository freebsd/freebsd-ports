# New ports collection makefile for:	sformat
# Date created:				16 December 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	sformat
PORTVERSION=	3.5
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/sformat/:sformat \
		${MASTER_SITE_LOCAL:S/$/:libschily,sformat/}
MASTER_SITE_SUBDIR=	marius/:libschily,sformat
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sformat \
		${LIBSCHILY}:libschily
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Allows formatting/partitioning/analysis/repairing of SCSI disks

LIBSCHILY=	libschily-2.01.01a07.tar.gz
USE_GMAKE=	yes
MAN1=		sformat.1

.include <bsd.port.pre.mk>

CCOM!=		${BASENAME} ${CC}
MAKE_ENV=	CCOM=${CCOM} LANG=C
SFMTTARGET=	${ARCH}-freebsd-${CCOM}

post-extract:
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${LIBSCHILY} ${EXTRACT_AFTER_ARGS}
.for i in config.guess config.sub
	@${CP} ${PORTSDIR}/Templates/${i} ${WRKSRC}/conf
.endfor
.if ${SFMTTARGET} != "i386-freebsd-cc"
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
