# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	pardiff
PORTVERSION=	0.9.4
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallelizing diff Filter, converts diff output to paralleled format

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
GNU_CONFIGURE=	yes

MAN1=	pardiff.1 diffp.1

PLIST_FILES=	bin/pardiff bin/diffp
.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog README
.endif

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/pardiff
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/pardiff/
.endfor
.endif

.include <bsd.port.mk>
