# New ports collection makefile for:	rlpr
# Date created:		11 April 1999
# Whom:			Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	rlpr
PORTVERSION=	2.05
CATEGORIES=	print net
MASTER_SITES=	ftp://www.truffula.com/pub/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Send print jobs to lpd servers anywhere on a network

#LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
#CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib -lintl"
CONFIGURE_ENV=	CPPFLAGS="-I${FILESDIR}"
CONFIGURE_ARGS=	--disable-nls --without-catgets
USE_REINPLACE=	yes

post-patch:
	# Replacing references to /etc/rlprrc to ${PREFIX}/etc/rlprrc
	${REINPLACE_CMD} -e 's%/etc/rlprrc%${PREFIX}/etc/rlprrc%g' \
		${WRKSRC}/src/rlprrc.h \
		`${GREP} -Fl /etc/rlprrc ${WRKSRC}/man/*.[0-9n]`

post-install:
	# Making the installed binaries suid,\
		      for the remote lpds to talk to them"
	${CHMOD} 4511 ${PREFIX}/bin/rlpq ${PREFIX}/bin/rlpr ${PREFIX}/bin/rlprm

MAN1=	rlpr.1 rlpq.1 rlprm.1
MAN5=	rlprrc.5
MAN8=	rlprd.8

.include <bsd.port.mk>
