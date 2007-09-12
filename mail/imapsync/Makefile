# New ports collection makefile for:	imapsync
# Date created:		14 Jan 2005
# Whom:			Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	imapsync
PORTVERSION=	1.223
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.linux-france.org/prj/imapsync/dist/ \
		http://christianserving.org/ports/mail/imapsync/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@christianserving.org
COMMENT=	IMAP synchronization copy or migration tool

BUILD_DEPENDS=	${SITE_PERL}/Mail/IMAPClient.pm:${PORTSDIR}/mail/p5-Mail-IMAPClient \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes
POD2MAN?=	pod2man

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
