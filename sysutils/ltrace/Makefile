# ex:ts=8
# Ports collection makefile for:  ltrace
# Date created:			  Mon Oct 15, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ltrace
PORTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://utopia.knoware.nl/users/driehuis/
DISTNAME=	${PORTNAME}-${PORTVERSION}-fbsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Library Tracer -- similar to strace, but trace library calls

# Although there is sparc code under the Linux/ directory, there is nothing
# other than i386 in the FreeBSD/ directory as of 2003-18-06.
ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_FILES=	bin/ltrace etc/ltrace.conf

CONFLICTS=	polygraph-2*

MAN1=		ltrace.1

post-patch:
	${REINPLACE_CMD} \
		-e 's|"/etc/ltrace.conf"|"${PREFIX}/etc/ltrace.conf"|g' \
		${WRKSRC}/ltrace.c
	${REINPLACE_CMD} -e 's|^\(CC\)|#\1|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ltrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/ltrace.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/ltrace.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
