# New ports collection makefile for: dump9660
# Date Created:		14 Jun 2002
# Whom:			wkj
#
# $FreeBSD$
#

PORTNAME=	dump9660
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.eecs.harvard.edu/~wkj/Software/dump9660/
DISTNAME=	dump9660
EXTRACT_SUFX=	.tgz

MAINTAINER=	dump9660-port@eecs.harvard.edu

MAN8=		mk9660.8
MAN5=		proto.5
MLINKS=		mk9660.8 dump9660.8
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

# 386(=i386), alpha, sparc
# PowerPC should be OK, too
OBJTYPE!=	${UNAME} -m | ${SED} -e 's;i.86;386;'
MAKE_ENV	+= systype=${OPSYS} objtype=${OBJTYPE}

post-patch:
	${REINPLACE_CMD} -e 's,@@LOCAL@@,${PREFIX},g' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
