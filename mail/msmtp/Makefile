# Ports collection makefile for:  msmtp
# Date created:                   22 Aug 2003
# Whom:                           R.I.Pienaar <rip@devco.net>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	0.5.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	msmtp

MAINTAINER=	rip@devco.net
COMMENT=	SMTP plugin for MUAs

USE_GETOPT_LONG=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes

MAN1=		msmtp.1
PLIST_FILES=	bin/msmtp

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|g ; \
		s|CC =|CC ?=|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msmtp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/msmtp.1 ${PREFIX}/man/man1

post-install:
	@${ECHO_CMD} "*****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Please note that since version 0.5.0 this program uses a configuration file"
	@${ECHO_CMD} "rather than the old command line options, see the man page."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "***************************************************************************##"

.include <bsd.port.mk>
