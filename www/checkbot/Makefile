# New ports collection makefile for:	checkbot
# Version required:			1.51
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $Id: Makefile,v 1.8 1997/06/24 18:43:25 jfitz Exp $
#

DISTNAME=	checkbot-1.51
CATEGORIES=	www perl5
MASTER_SITES=	http://www.xs4all.nl/~graaff/checkbot/

MAINTAINER=	wosch@FreeBSD.ORG

BUILD_DEPENDS=  \
		${PORTSDIR}/net/p5-Net \
		${PORTSDIR}/www/p5-libwww \
		${PORTSDIR}/mail/p5-Mail-Tools

MAN1=		checkbot.1
USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
