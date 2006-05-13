# Ports collection makefile for:  more
# Date created:			  24 May 2000
# Whom:				  Tim van der Hoek <hoek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	44bsd-more
PORTVERSION=	${RELDATE}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hoek

MAINTAINER=	hoek@FreeBSD.org
COMMENT=	The pager installed with FreeBSD before less(1) was imported

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes

MAN1=		44bsd-more.1

RELDATE=	20000521

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
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/more.1 ${PREFIX}/man/man1/44bsd-more.1
.for f in default.morerc less.morerc most.morerc
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/more.help ${PREFIX}/share/misc/44bsd-more.help
	${INSTALL_PROGRAM} ${WRKSRC}/more ${PREFIX}/bin/44bsd-more

tarup:
	cd ${WRKSRC} && tar cyf /tmp/${DISTFILES} RCS
	scp /tmp/${DISTFILES} freefall:public_html/dists

.include <bsd.port.mk>
