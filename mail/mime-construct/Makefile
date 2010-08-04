# New ports collection makefile for:	mime-construct
# Date created:				Tue 02 Mar 2010
# Whom:					Alexey V. Degtyarev <alexey@renatasystems.org>
#
# $FreeBSD$
#

PORTNAME=	mime-construct
PORTVERSION=	1.11
CATEGORIES=	mail
MASTER_SITES=	http://www.argon.org/~roderick/ \
		ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Construct and optionally send MIME messages from command line

BUILD_DEPENDS=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Proc-WaitStat>=0:${PORTSDIR}/devel/p5-Proc-WaitStat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		mime-construct.1

.include <bsd.port.mk>
