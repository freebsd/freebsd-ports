# New ports collection makefile for:	wmtop
# Date created:		07 May 2000
# Whom:			Dan Piponi <wmtop@tanelorn.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	wmtop
PORTVERSION=	0.84
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://wmtop.sourceforge.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wmtop@tanelorn.demon.co.uk

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	freebsd

MAN1=		wmtop.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wmtop.1 ${PREFIX}/man/man1
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in BUGS CHANGES COPYING README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
