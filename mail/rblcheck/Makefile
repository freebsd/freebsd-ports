# New ports collection makefile for:	rblcheck
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	rblcheck
PORTVERSION=	1.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	moro@remus.dti.ne.jp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-build:
	@${PERL} -pi -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/rbl

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
