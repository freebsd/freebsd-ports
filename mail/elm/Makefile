# Created by: dhagan@cs.vt.edu
# $FreeBSD$

PORTNAME=	elm
PORTVERSION=	2.5.8
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://instinct.org/elm/files/tarballs/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	toasty@dragondata.com
COMMENT=	A once-popular mail user agent, version 2.5.x

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-D_SIZE_T

WRKSRC=			${WRKDIR}/elm${PORTVERSION}
NO_LATEST_LINK=		yes
USES=		gettext
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=		PREFIX="${PREFIX}"
CONFIGURE_ARGS=		-d
MAKE_FLAGS=		CATMAN=catman-none
MAN1=			answer.1 checkalias.1 elm.1 elmalias.1 fastmail.1 \
			frm.1 listalias.1 messages.1 newalias.1 newmail.1 \
			printmail.1 readmsg.1 mmencode.1
MLINKS=			frm.1 nfrm.1 newmail.1 wnewmail.1

NO_STAGE=	yes
.include <bsd.port.mk>
