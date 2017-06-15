# Created by: marius@alchemy.franken.de
# $FreeBSD$

PORTNAME=	sformat
PORTVERSION=	3.5
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/sformat/:sformat \
		LOCAL/marius:libschily,sformat
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sformat \
		${LIBSCHILY}:libschily
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Allows formatting/partitioning/analysis/repairing of SCSI disks

BROKEN_aarch64=		Does not build: No rule to make target RULES/arm64-freebsd-cc.rul
BROKEN_mips64=		Does not build: No rule to make target RULES/mips-freebsd-cc.rul
BROKEN_powerpc64=	Does not build

LIBSCHILY=	libschily-2.01.01a07.tar.gz
USES=		gmake

.include <bsd.port.pre.mk>

CCOM!=		${BASENAME} ${CC}
MAKE_ENV=	CCOM=${CCOM}
SFMTTARGET=	${ARCH:S/powerpc64/powerpc/}-freebsd-${CCOM}

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
.for i in include/schily.h libschily/fexec.c libschily/libschily-mapvers
	@${REINPLACE_CMD} -e 's|fexecve|js_fexecve|g' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e 's|int	getline|int	get_line|g' ${WRKSRC}/include/schily.h
	@${REINPLACE_CMD} -e 's|(getline(|(get_line(|g' ${WRKSRC}/sformat/io.c \
		${WRKSRC}/libscg/scsitransp.c
	@${REINPLACE_CMD} -e 's| getline(| get_line(|g' ${WRKSRC}/sformat/io.c \
		${WRKSRC}/sformat/defect.c
	@${REINPLACE_CMD} -e 's|^getline|get_line|g' ${WRKSRC}/libschily/stdio/fgetline.c
	@${REINPLACE_CMD} -e 's|)getline|)get_line|g' ${WRKSRC}/sformat/diskfmt.c \
		${WRKSRC}/sformat/makelabel.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sformat/OBJ/${SFMTTARGET}/sformat \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sformat/sformat.dat ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/sformat/sformat.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
