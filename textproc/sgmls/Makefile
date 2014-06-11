# Created by: Eugene Furs <justas@mbank.lv>
# $FreeBSD$

PORTNAME=	sgmls
PORTVERSION=	1.1.91
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sgmls/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML parser

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

PROGS=		sgmls sgmlsasp rast
PKGDOCS=	ChangeLog INSTALL LICENSE NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile

post-build:
.for file in ${PROGS}
	@${STRIP_CMD} ${WRKSRC}/${file}
.endfor
	@cd ${WRKSRC} && ${MAKE} test

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@-${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PKGDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
