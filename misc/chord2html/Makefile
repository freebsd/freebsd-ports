# ex:ts=8
# Ports collection makefile for:	chord2html
# Date created:			Sep 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	chord2html
PORTVERSION=	1.3
CATEGORIES=	misc
MASTER_SITES=	http://helllabs.org/~claudio/chord/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	chord2html.1

post-patch:
	@${PERL} -pi -e "s,/usr/bin/perl,${PERL},g ; \
		s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/chord2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chord2html ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chord2html.css ${DATADIR}

.include <bsd.port.mk>
