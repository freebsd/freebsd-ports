# New ports collection makefile for:   gotmail
# Date created:        9 August 2001
# Whom:                Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	gotmail
PORTVERSION=	0.7.4
CATEGORIES=	mail perl5
MASTER_SITES=	http://ssl.usu.edu/paul/gotmail/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	freebsd-ports@FreeBSD.org

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/libnet.cfg:${PORTSDIR}/net/p5-Net

MAN1=		${PORTNAME}.1
NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-patch:
	${PERL} -pi -e 's|\r$$||' ${WRKSRC}/${PORTNAME}
	${PERL} -pi -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/${PORTNAME}

do-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${MANPREFIX}/man/man1
.endfor # i in ${MAN1}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in ChangeLog README sample.gotmailrc
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor # i in ChangeLog README sample.gotmailrc
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>
