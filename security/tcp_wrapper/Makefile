# New ports collection makefile for:	tcp_wrapper
# Version required:	6.3
# Date created:		27 Oct 1994
# Whom:			torstenb
#
# $Id$
#

DISTNAME=	tcp_wrappers_6.3
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/
EXTRACT_CMD=	${.CURDIR}/scripts/extract.sh
EXTRACT_ARGS=	${WRKSRC}
EXTRACT_SUFX=	.shar.Z

pre-install:
	@mkdir -p ${PREFIX}/sbin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/etc
	@mkdir -p ${PREFIX}/man/man3
	@mkdir -p ${PREFIX}/man/man5
	@mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
