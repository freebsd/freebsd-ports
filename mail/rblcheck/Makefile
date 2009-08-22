# New ports collection makefile for:	rblcheck
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	rblcheck
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	moro@remus.dti.ne.jp
COMMENT=	Command-line interface to Paul Vixie's RBL filter

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/rbl ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
	@${INSTALL_DATA} ${FILESDIR}/rblcheckrc.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog INSTALL NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
