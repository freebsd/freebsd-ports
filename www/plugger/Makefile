# New ports collection makefile for:	plugger
# Date created:		11 Februrary 1999
# Whom:			Jay Sachs <sachs@cs.williams.edu>
#
# $FreeBSD$
#

PORTNAME=	plugger
PORTVERSION=	3.3
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/ \
		ftp://ftp.netscape.com/pub/sdk/plugin/unix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unix-sdk-3.0b5.tar.Z

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/netscape/plugins:${PORTSDIR}/www/netscape47-navigator

#BROKEN_ELF=	"Needs a.out c++rt0.o file"

MAN7=		plugger.7
MANCOMPRESSED=	no
ALL_TARGET=	freebsd-elf

post-patch:
	${MV} ${WRKSRC}/plugger.c ${WRKSRC}/plugger.c.orig
	${SED} \
	  -e 's#/usr/local/#${PREFIX}/#' \
	  ${WRKSRC}/plugger.c.orig > ${WRKSRC}/plugger.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/plugger.so ${PREFIX}/lib/netscape/plugins
	${INSTALL_MAN}  ${WRKSRC}/plugger.7  ${MANPREFIX}/man/man7
	${INSTALL_DATA} ${WRKSRC}/pluggerrc  ${PREFIX}/etc/pluggerrc.sample

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:/usr/local:${PREFIX}:'

.include <bsd.port.mk>
