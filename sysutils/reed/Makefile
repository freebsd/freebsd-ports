# New ports collection makefile for:	reed
# Date created:				7 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	reed
PORTVERSION=	4.7
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configures
CONFIGURE_ENV=	INCDIR="${LOCALBASE}/include"

CFLAGS+=	-I${LOCALBASE}/include

MAN1=	breed.1 reed.1 wrap.1

post-patch:
	@${PERL} -pi -e 's!/usr/local/!${PREFIX}!g' ${WRKSRC}/configures
	@${PERL} -pi -e 's!sys/dir.h!dirent.h!g' ${WRKSRC}/src/reed.h
	@${PERL} -pi -e 's!-O2!${CFLAGS}!' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/breed ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrap ${PREFIX}/bin
.for file in ${MAN1}
	${INSTALL_SCRIPT} ${WRKSRC}/man/${file} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
