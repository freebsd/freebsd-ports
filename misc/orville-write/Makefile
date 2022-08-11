PORTNAME=	orville-write
PORTVERSION=	2.55
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced replacement for write/mesg

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type

PLIST_FILES=	"@(,,4711) bin/amin" "@(,,4711) bin/helpers" "@(,,4711) bin/huh" \
		bin/jot "@(,,4711) bin/mesg" bin/tel bin/telegram \
		"@(,,6711) bin/write" etc/orville.conf etc/wrthist etc/wrttmp \
		man/man1/amin.1.gz man/man1/helpers.1.gz man/man1/huh.1.gz \
		man/man1/mesg.1.gz man/man1/write.1.gz

MAKE_JOBS_UNSAFE=yes

do-install:
.for i in amin helpers huh mesg
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in write
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
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

.include <bsd.port.mk>
