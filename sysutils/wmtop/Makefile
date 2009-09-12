# New ports collection makefile for:	wmtop
# Date created:		07 May 2000
# Whom:			Dan Piponi <wmtop@tanelorn.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	wmtop
PORTVERSION=	0.84
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://ftp1.sourceforge.net/wmtop/ \
		SF		


MAINTAINER=	uqs@spoerlein.net
COMMENT=	Windowmaker dock app to display top 3 CPU consuming processes

USE_XORG=	xpm x11
ALL_TARGET=	freebsd

MAN1=		wmtop.1
PLIST_FILES=	bin/wmtop

.if !defined(NOPORTDOCS)
PORTDOCS=	BUGS CHANGES COPYING README TODO
.endif

post-patch:
	${REINPLACE_CMD} -e 's/^\(LIBS.*\)/\1 -lkvm/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/^\(FLAGS.*\)/\1 -DNO_PROCFS/' ${WRKSRC}/Makefile

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

.include <bsd.port.mk>
