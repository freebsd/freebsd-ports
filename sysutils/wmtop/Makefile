# New ports collection makefile for:	wmtop
# Date created:		07 May 2000
# Whom:			Dan Piponi <wmtop@tanelorn.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	wmtop
PORTVERSION=	0.84
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://ftp1.sourceforge.net/wmtop/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windowmaker dock app to display top 3 CPU consuming processes

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	freebsd

MAN1=		wmtop.1
PLIST_FILES=	bin/wmtop

.if !defined(NOPORTDOCS)
PORTDOCS=	BUGS CHANGES COPYING README TODO
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
post-patch:
	${REINPLACE_CMD} -e 's/^\(LIBS.*\)/\1 -lkvm/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/^\(FLAGS.*\)/\1 -DNO_PROCFS/' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wmtop.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in BUGS CHANGES COPYING README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.post.mk>
