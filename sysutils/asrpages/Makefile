# New ports collection makefile for:	asrpages
# Version required:	0.1
# Date created:		6 Nov 1997
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $Id: Makefile,v 1.5 1998/09/19 05:48:06 steve Exp $
#

DISTNAME=	asrpages
PKGNAME=	asrpages-0.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.winternet.com/users/eric/
DISTFILES=	asr.pages.tar

MAINTAINER=	axl@iafrica.com

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

MAN1=		c.1 rtfm.1 slave.1 sysadmin.1 think.1 whack.1
MAN2=		people.2
MAN3=		chastise.3
MAN5=		normality.5
MAN8=		bosskill.8 ctluser.8 guru.8 knife.8 lart.8 luser.8 nuke.8 \
		pmsd.8

do-install:
	cd ${WRKSRC} && \
	${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1 && \
	${INSTALL_MAN} ${MAN2} ${PREFIX}/man/man2 && \
	${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3 && \
	${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5 && \
	${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
