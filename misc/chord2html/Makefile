# Ports collection makefile for:	chord2html
# Date created:				Sep 11, 2002
# Whom:					ijliao
#
# $FreeBSD$
#
# $Tecnik: ports/misc/chord2html/Makefile,v 1.3 2005/12/14 11:41:25 itetcu Exp $
#

PORTNAME=	chord2html
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Convert CHORD input files to HTML

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	chord2html.1

PLIST_FILES=	bin/chord2html share/chord2html/chord2html.css
PLIST_DIRS=	share/chord2html

post-patch:
	@${PERL} -pi -e "s,/usr/bin/perl,${PERL},g ; \
			 s,%%PREFIX%%,${PREFIX},g ; \
			 s,chord2html.css,${PREFIX}/share/chord2html/chord2html.css," \
		${WRKSRC}/chord2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chord2html ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chord2html.css ${DATADIR}

.include <bsd.port.mk>
