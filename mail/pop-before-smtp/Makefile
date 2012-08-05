# New ports collection makefile for:	pop-before-smtp
# Date created:				March 7, 2003
# Whom:					Eric W. Bates
#
# $FreeBSD$
#

PORTNAME=	pop-before-smtp
PORTVERSION=	1.42
CATEGORIES=	mail perl5
MASTER_SITES=	SF/popbsmtp/Source%20tar/${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A log parser to identify valid POP/IMAP logins for later smtp

RUN_DEPENDS=	p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_RC_SUBR=	pop-before-smtp
SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL}

MAN8=		${PORTNAME}.8

post-patch:
	@${REINPLACE_CMD} 's|^#!/usr/bin/perl|#!${PERL}|; \
		s|/etc/postfix/pop-before-smtp|${PREFIX}/etc/postfix/pop-before-smtp|g;' \
		${WRKSRC}/pop-before-smtp
pre-install:
	@pod2man ${WRKSRC}/${PORTNAME} > ${MANPREFIX}/man/man8/${PORTNAME}.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pop-before-smtp ${PREFIX}/sbin
	${INSTALL_SCRIPT} \
		${WRKSRC}/pop-before-smtp-conf.pl \
		${PREFIX}/etc/pop-before-smtp-conf.pl.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in README.QUICKSTART README.rootless-install popauth.m4
	${INSTALL_DATA} ${WRKSRC}/contrib/${FILE} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/popa3d
.for FILE in README popa3d-0.4.patch popa3d-0.6.4.patch
	${INSTALL_DATA} ${WRKSRC}/contrib/popa3d/${FILE} ${DOCSDIR}/popa3d
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
