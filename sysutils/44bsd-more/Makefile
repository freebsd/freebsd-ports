# Ports collection makefile for:  more
# Date created:			  24 May 2000
# Whom:				  Tim van der Hoek <hoek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	44bsd-more
PORTVERSION=	${RELDATE}
CATEGORIES=	misc
MASTER_SITES=	http://people.FreeBSD.org/~hoek/dists/

MAINTAINER=	hoek@FreeBSD.org

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes

MAN1=		44bsd-more.1

RELDATE=	20000521
EXAMPDIR=	${PREFIX}/share/examples/44bsd-more

post-extract:
	-cd ${WRKSRC} && co -d${RELDATE} RCS/*,v

do-patch:
	${PERL} -pi.orig -e \
	    's!/usr/share/misc/more.help!${PREFIX}/share/misc/44bsd-more.help!'\
	    ${WRKSRC}/pathnames.h

do-install:
	${MKDIR} ${EXAMPDIR}
	${INSTALL_MAN} ${WRKSRC}/more.1 ${PREFIX}/man/man1/44bsd-more.1
	${INSTALL_DATA} ${WRKSRC}/default.morerc ${EXAMPDIR}
	${INSTALL_DATA} ${WRKSRC}/less.morerc ${EXAMPDIR}
	${INSTALL_DATA} ${WRKSRC}/most.morerc ${EXAMPDIR}
	${INSTALL_DATA} ${WRKSRC}/more.help ${PREFIX}/share/misc/44bsd-more.help
	${INSTALL_PROGRAM} ${WRKSRC}/more ${PREFIX}/bin/44bsd-more

tarup:
	cd ${WRKSRC} && tar cyf /tmp/${DISTFILES} RCS
	scp /tmp/${DISTFILES} freefall:public_html/dists

.include <bsd.port.mk>
