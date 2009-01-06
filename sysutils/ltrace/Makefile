# ex:ts=8
# Ports collection makefile for:  ltrace
# Date created:			  Mon Oct 15, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ltrace
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.huji.ac.il/~bla/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Library Tracer -- similar to strace, but trace library calls

LIB_DEPENDS=	elf.0:${PORTSDIR}/devel/libelf

# The FreeBSD port exists only for i386
ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_FILES=	bin/ltrace etc/ltrace.conf

CONFLICTS=	polygraph-2*

MAN1=		ltrace.1

post-patch:
	${REINPLACE_CMD} -e 's|^\(CC\)|#\1|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ltrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/ltrace.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/ltrace.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
