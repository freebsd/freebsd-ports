# New ports collection makefile for:  	bbdate
# Date created:		May 3 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bbdate
PORTVERSION=	0.2.4
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbtools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool made for Blackbox that displays the date in a decorated window

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bbdate share/bbtools/README.bbdate \
		share/bbtools/bbdate.conf share/bbtools/bbdate.nobb \
		share/bbtools/bbdate.style share/bbtools/bbtoolsrc.in

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
