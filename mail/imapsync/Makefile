# New ports collection makefile for:	imapsync
# Date created:		14 Jan 2005
# Whom:			Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	imapsync
PORTVERSION=	1.315
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.linux-france.org/prj/${PORTNAME}/dist/ \
		http://christianserving.org/ports/mail/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@christianserving.org
COMMENT=	IMAP synchronization copy or migration tool

BUILD_DEPENDS=	p5-Mail-IMAPClient>0:${PORTSDIR}/mail/p5-Mail-IMAPClient \
		p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Date-Manip>0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

POD2MAN?=	pod2man

do-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|g' \
		${WRKSRC}/${PORTNAME}

do-install:
	${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
