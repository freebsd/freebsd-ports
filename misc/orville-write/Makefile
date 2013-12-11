# Created by: James Howard <howardj@wam.umd.edu>
# $FreeBSD$

PORTNAME=	orville-write
PORTVERSION=	2.55
CATEGORIES=	misc
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced replacement for write/mesg

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type

PLIST_FILES=	bin/amin bin/helpers bin/huh bin/jot bin/mesg bin/tel \
		bin/telegram bin/write etc/orville.conf etc/wrthist etc/wrttmp \
		man/man1/amin.1.gz man/man1/helpers.1.gz man/man1/huh.1.gz \
		man/man1/mesg.1.gz man/man1/write.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/utmpx-wrttmp.h \
		${PATCHDIR}/utmpx-wrt_him.c \
		${PATCHDIR}/utmpx-wrt_me.c \
		${PATCHDIR}/utmpx-lib_common.c \
		${PATCHDIR}/utmpx-lib_common.h \
		${PATCHDIR}/utmpx-getutent.h \
		${PATCHDIR}/utmpx-getutent.c \
		${PATCHDIR}/utmpx-mesg.c \
		${PATCHDIR}/utmpx-amin.c \
		${PATCHDIR}/utmpx-huh.c \
		${PATCHDIR}/utmpx-helpers.c
.endif

do-install:
.for i in amin helpers huh mesg
	${INSTALL_PROGRAM} -m 4711 ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in write
	${INSTALL_PROGRAM} -m 6711 ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in jot tel telegram
	${LN} -sf write ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
.for i in orville.conf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/etc
.endfor
.for i in wrthist wrttmp
	${INSTALL_DATA} -m 600 /dev/null ${STAGEDIR}${PREFIX}/etc/${i}
.endfor
.for i in amin.1 helpers.1 huh.1 mesg.1 write.1
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
