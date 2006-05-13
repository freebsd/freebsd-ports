# New ports collection makefile for: dump9660
# Date Created:		14 Jun 2002
# Whom:			wkj
#
# $FreeBSD$
#

PORTNAME=	dump9660
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.morphisms.net/~wkj/Software/dump9660/
DISTNAME=	dump9660
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create an ISO 9660 image, possibly incrementally

MAN8=		mk9660.8
MAN5=		proto.5
MLINKS=		mk9660.8 dump9660.8

ONLY_FOR_ARCHS=	alpha i386 powerpc
OBJTYPE=	${MACHINE_ARCH:S/i386/386/:S/powerpc/power/}
MAKE_ENV=	systype=${OPSYS} objtype=${OBJTYPE}

post-patch:
	${REINPLACE_CMD} -e 's|@@LOCAL@@|${PREFIX}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|CC=.*|CC=${CC}|' \
		-e 's|XCFLAGS=.*|XCFLAGS=${CFLAGS} -DFREEBSD|' \
		${WRKSRC}/Make.FreeBSD
# The assembly files require pre-processing
	cd ${WRKSRC}/libunix; \
		for f in *.s; do ${MV} $$f $${f%.s}.S; done

.include <bsd.port.mk>
