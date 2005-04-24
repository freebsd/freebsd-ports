# New ports collection makefile for:	sgmls
# Date created:				Jun 2, 2000
# Whom:					Eugene Furs <justas@mbank.lv>
#
# $FreeBSD$
#

PORTNAME=	sgmls
PORTVERSION=	1.1.91
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sgmls/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML parser

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		sgmls.1 sgmlsasp.1 rast.1

PROGS=		sgmls sgmlsasp rast
DOCS=		ChangeLog INSTALL LICENSE NEWS README TODO

post-build:
.for file in ${PROGS}
	@${STRIP_CMD} ${WRKSRC}/${file}
.endfor
	@cd ${WRKSRC} && ${MAKE} test

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@-${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
