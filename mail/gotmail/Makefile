# New ports collection makefile for:   gotmail
# Date created:        9 August 2001
# Whom:                Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	gotmail
PORTVERSION=	0.6.6
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.hawkins.emu.id.au/gotmail/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in COPYING ChangeLog README TODO sample.gotmailrc
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
