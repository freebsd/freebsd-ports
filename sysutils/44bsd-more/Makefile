# Created by: Tim van der Hoek <hoek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	44bsd-more
PORTVERSION=	${RELDATE}
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The pager installed with FreeBSD before less(1) was imported

USES=		ncurses tar:bzip2
NO_WRKSUBDIR=	yes

CFLAGS=		-Wno-return-type
MAKE_ARGS=	LDADD="-lncurses"

RELDATE=	20000521

.include <bsd.port.pre.mk>

post-extract:
	-cd ${WRKSRC} && co RCS/*,v

post-patch:
	${REINPLACE_CMD} -e \
	    's!/usr/share/misc/more.help!${PREFIX}/share/misc/44bsd-more.help!'\
	    ${WRKSRC}/pathnames.h
	${CP} ${FILESDIR}/queue.h ${WRKSRC}
	${REINPLACE_CMD} -e 's/static char \*getvar/static const char \*getvar/' \
	    ${WRKSRC}/ncommand.c

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/more.1 ${STAGEDIR}${PREFIX}/man/man1/44bsd-more.1
.for f in default.morerc less.morerc most.morerc
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/more.help ${STAGEDIR}${PREFIX}/share/misc/44bsd-more.help
	${INSTALL_PROGRAM} ${WRKSRC}/more ${STAGEDIR}${PREFIX}/bin/44bsd-more

tarup:
	cd ${WRKSRC} && tar cyf /tmp/${DISTFILES} RCS
	scp /tmp/${DISTFILES} freefall:public_html/dists

.include <bsd.port.post.mk>
