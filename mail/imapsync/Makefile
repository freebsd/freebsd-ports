# New ports collection makefile for:	imapsync
# Date created:		14 Jan 2005
# Whom:			Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	imapsync
PORTVERSION=	1.255
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.linux-france.org/prj/imapsync/dist/:imapsync \
		${MASTER_SITE_PERL_CPAN:S/$/:imapclient229/} \
		http://christianserving.org/ports/mail/imapsync/:imapsync,imapclient229
MASTER_SITE_SUBDIR=	Mail/:imapclient229
DISTFILES=	${DISTNAME}.tgz:imapsync \
		Mail-IMAPClient-2.2.9.tar.gz:imapclient229

MAINTAINER=	ports@christianserving.org
COMMENT=	IMAP synchronization copy or migration tool

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Date-Manip>0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes

MAN1=		${PORTNAME}.1

POD2MAN?=	pod2man

IMAPCLIENTNAME=	Mail-IMAPClient-2.2.9
IMAPCLIENTWRKSRC=	${WRKDIR}/${IMAPCLIENTNAME}
IMAPCLIENTDIR=	${DATADIR}/${IMAPCLIENTNAME}

do-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|g' \
		-e '2{p;s|^|use lib '"'"'${IMAPCLIENTDIR}/lib/perl5/site_perl'"'"';|;G;}' \
		${WRKSRC}/${PORTNAME}

do-configure:
	(cd ${IMAPCLIENTWRKSRC} && echo 'n' | ${PERL} Makefile.PL PREFIX=${IMAPCLIENTDIR})

do-build:
	${MAKE} -C ${IMAPCLIENTWRKSRC} PREFIX=${IMAPCLIENTDIR}

do-install:
	${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1
	${MAKE} -C ${IMAPCLIENTWRKSRC} pure_install PREFIX=${IMAPCLIENTDIR} INSTALLSITEMAN3DIR=none

.include <bsd.port.mk>
