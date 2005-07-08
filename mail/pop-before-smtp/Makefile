# New ports collection makefile for:	pop-before-smtp
# Date created:				March 7, 2003
# Whom:					Eric W. Bates
#
# $FreeBSD$
#

PORTNAME=	pop-before-smtp
PORTVERSION=	1.37
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	popbsmtp

MAINTAINER=	ericx@vineyard.net
COMMENT=	A log parser to identify valid POP/IMAP logins for later smtp

RUN_DEPENDS=	${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
POD2MAN?=	pod2man
PKGMESSAGE=	${WRKDIR}/.pkg-message
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
MAN8=		${PORTNAME}.8

# Override this as you see fit
POPBSMTP_RC_SCRIPT?=	${PREFIX}/etc/rc.d/pop-before-smtp.sh.sample

post-patch:
	@${REINPLACE_CMD} 's|^#!/usr/bin/perl|#!${PERL}|; \
		s|/etc/postfix/pop-before-smtp|${PREFIX}/etc/postfix/pop-before-smtp|g;' \
		${WRKSRC}/pop-before-smtp

pre-install:
	@${POD2MAN} ${WRKSRC}/${PORTNAME} > ${PREFIX}/man/man8/${PORTNAME}.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pop-before-smtp ${PREFIX}/sbin
	${INSTALL_SCRIPT} \
		${WRKSRC}/pop-before-smtp-conf.pl \
		${PREFIX}/etc/pop-before-smtp-conf.pl.sample
	@${SED} -e "s|%PREFIX%|${PREFIX}|g" \
		< ${FILESDIR}/pop-before-smtp.sh > ${POPBSMTP_RC_SCRIPT}
	@${CHMOD} 755 ${POPBSMTP_RC_SCRIPT}
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
	@${SED} -e "s|%PREFIX%|${PREFIX}|" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
