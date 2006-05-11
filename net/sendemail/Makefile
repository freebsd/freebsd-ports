# New ports collection makefile for:	sendEmail
# Date created:				2005-12-17
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#
# $Tecnik: ports/net/sendemail/Makefile,v 1.1 2005/12/17 01:22:24 itetcu Exp $

PORTNAME=	sendEmail
PORTVERSION=	1.52
CATEGORIES=	net
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendEmail/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Lightweight, completly command line based, SMTP email agent

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/sendEmail
PORTDOCS=	CHANGELOG README TODO

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" \
		${WRKSRC}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME} ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG README TODO ${DOCSDIR}
.endif

.include <bsd.port.mk>
