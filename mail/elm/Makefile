# New ports collection makefile for:    elm25
# Date created:				04 Feb 2000
# Whom:					dhagan@cs.vt.edu
#
# $FreeBSD$
#

PORTNAME=	elm
PORTVERSION=	2.5.6
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.virginia.edu/pub/elm/ \
		http://www.dragondata.com/software/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	toasty@dragondata.com
COMMENT=	A once-popular mail user agent, version 2.5.x

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

WRKSRC=			${WRKDIR}/elm${PORTVERSION}
NO_LATEST_LINK=		yes
USE_GETTEXT=		yes
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=		PREFIX="${PREFIX}"
MAN1=			answer.1 checkalias.1 elm.1 elmalias.1 fastmail.1 \
			frm.1 listalias.1 messages.1 newalias.1 newmail.1 \
			printmail.1 readmsg.1 mmencode.1
MLINKS=			frm.1 nfrm.1 newmail.1 wnewmail.1

.include <bsd.port.mk>
