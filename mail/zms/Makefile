# New ports collection makefile for: zms
# Date created:        12 February 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	zms
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cpan.org/authors/id/V/VV/VVELOX/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A specialized mail gateway system for using user specified SMTP server

RUN_DEPENDS=	${SITE_PERL}/Net/LDAP/Entry.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Net/Server/Mail/ESMTP.pm:${PORTSDIR}/mail/p5-Net-Server-Mail \
		${SITE_PERL}/Authen/Simple/PAM.pm:${PORTSDIR}/security/p5-Authen-Simple-PAM \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny \
		${SITE_PERL}/Net/SMTP/TLS.pm:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		${SITE_PERL}/Net/SMTP_auth.pm:${PORTSDIR}/mail/p5-Net-SMTP_auth \
		${SITE_PERL}/Net/RBLClient.pm:${PORTSDIR}/dns/p5-Net-RBLClient \
		${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${SITE_PERL}/IPC/Shareable.pm:${PORTSDIR}/devel/p5-IPC-Shareable

USE_PERL5=	yes

NO_WRKSUBDIR=	yes

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=${PORTNAME} --center=${PORTNAME}" user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/zms
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
